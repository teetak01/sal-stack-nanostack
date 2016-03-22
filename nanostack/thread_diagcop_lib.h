/*
 * Copyright (c) 2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: LicenseRef-PBL
 *
 * Licensed under the Permissive Binary License, Version 1.0 (the "License"); you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * https://www.mbed.com/licenses/PBL-1.0
 *
 * See the License for the specific language governing permissions and limitations under the License.
 *
 */

#ifndef NANOSTACK_SOURCE_6LOWPAN_THREAD_THREAD_DIAGCOP_LIB_H_
#define NANOSTACK_SOURCE_6LOWPAN_THREAD_THREAD_DIAGCOP_LIB_H_

#include "ns_types.h"
#include "thread_meshcop_lib.h" // this uses the same parser functions than meshcop but different message types

/**
 * CoAP diagnostic TLV definitions
 * Note that these TLV types overlap with meshcop
 * and must not be used in same messages.
*/
#define DIAGCOP_TLV_SOURCE_ADDRESS                           0
#define DIAGCOP_TLV_ADDRESS16                                1
#define DIAGCOP_TLV_MODE                                     2
#define DIAGCOP_TLV_TIMEOUT                                  3
#define DIAGCOP_TLV_CONNECTIVITY                             4
#define DIAGCOP_TLV_ROUTING_TABLE                            5
#define DIAGCOP_TLV_LEADER_DATA                              6
#define DIAGCOP_TLV_NETWORK_DATA                             7
#define DIAGCOP_TLV_IPV6_ADDRESS_LIST                        8
#define DIAGCOP_TLV_PACKETS_SENT                             9
#define DIAGCOP_TLV_PACKETS_RECEIVED                        10
#define DIAGCOP_TLV_PACKETS_DROPPED_TX                      11
#define DIAGCOP_TLV_PACKETS_DROPPED_RX                      12
#define DIAGCOP_TLV_SECURITY_ERRORS                         13
#define DIAGCOP_TLV_RETRIES                                 14
#define DIAGCOP_TLV_VOLTAGE                                 15
#define DIAGCOP_TLV_CHILD_TABLE                             16
#define DIAGCOP_TLV_GET                                     13

/**
 * \brief Write array TLV.
 *
 * \param ptr A pointer to array in which to write the TLV.
 * \param type The type of TLV.
 * \param length The length of the data that is written in TLV.
 * \param data The array for TLV value.
 * \return pointer The value for writing the next TLV.
 */
#define thread_diagcop_tlv_data_write(ptr,type,length,data) thread_meshcop_tlv_data_write(ptr,type,length,data)

/**
 * \brief Write 1 byte length TLV.
 *
 * \param ptr A pointer to array in which to write the TLV.
 * \param type The type of TLV.
 * \param data value.
 * \return pointer value for writing the next TLV.
 */
#define thread_diagcop_tlv_data_write_uint8(ptr,type,data) thread_meshcop_tlv_data_write_uint8(ptr,type,data)

/**
 * \brief Write 2 byte length TLV.
 *
 * \param ptr pointer for array where to write the TLV.
 * \param type Type of TLV.
 * \param data value.
 * \return pointer value for writing the next TLV.
 */
#define thread_diagcop_tlv_data_write_uint16(ptr,type,data) thread_meshcop_tlv_data_write_uint16(ptr,type,data)

/**
 * \brief Write 4 byte length TLV.
 *
 * \param ptr pointer for array where to write the TLV.
 * \param type Type of TLV.
 * \param data value.
 * \return pointer value for writing the next TLV.
 */
#define thread_diagcop_tlv_data_write_uint32(ptr,type,data) thread_meshcop_tlv_data_write_uint32(ptr,type,data)

/**
 * \brief Write 8 byte length TLV.
 *
 * \param ptr pointer for array where to write the TLV.
 * \param type Type of TLV.
 * \param data value.
 * \return pointer value for writing the next TLV.
 */
#define thread_diagcop_tlv_data_write_uint64(ptr,type,data) thread_meshcop_tlv_data_write_uint64(ptr,type,data)

/**
 * \brief Find TLV from message.
 *
 * \param ptr Message buffer.
 * \param length Length of the message buffer to validate message.
 * \param type Type of TLV searched.
 * \param result_ptr Pointer value is given as result if length is positive. Can be NULL which only searches for the length.
 * \return The length of the TLV data found
 * \return 0 if TLV is empty or no TLV found.
 * \return negative value indicates corrupted message.
 */
#define thread_diagcop_tlv_find(ptr,length,type,result) thread_meshcop_tlv_find(ptr,length,type,result)

/**
 * \brief Read 1 byte length TLV.
 *
 * \param ptr pointer TLV message array.
 * \param length length of TLV message array.
 * \param type Type of TLV.
 * \param data_ptr pointer to variable where the value is read.
 * \return pointer length of TLV 1 if success. 0 means TLV not found or does not have any data.
 * Any other value indicates that TLV is not as expected.
 */
#define thread_diagcop_tlv_data_get_uint8(ptr,length,type,data) thread_meshcop_tlv_data_get_uint8(ptr,length,type,data)

/**
 * \brief Read 2 byte length TLV.
 *
 * \param ptr pointer TLV message array.
 * \param length length of TLV message array.
 * \param type Type of TLV.
 * \param data_ptr pointer to variable where the value is read.
 * \return pointer length of TLV 2 if success. 0 means TLV not found or does not have any data.
 * Any other value indicates that TLV is not as expected.
 */
#define thread_diagcop_tlv_data_get_uint16(ptr,length,type,data) thread_meshcop_tlv_data_get_uint16(ptr,length,type,data)

/**
 * \brief Read 4 byte length TLV.
 *
 * \param ptr pointer TLV message array.
 * \param length length of TLV message array.
 * \param type Type of TLV.
 * \param data_ptr pointer to variable where the value is read.
 * \return pointer length of TLV 4 if success. 0 means TLV not found or does not have any data.
 * Any other value indicates that TLV is not as expected.
 */
#define thread_diagcop_tlv_data_get_uint32(ptr,length,type,data) thread_meshcop_tlv_data_get_uint32(ptr,length,type,data)

/**
 * \brief Read 8 byte length TLV.
 *
 * \param ptr pointer TLV message array.
 * \param length length of TLV message array.
 * \param type Type of TLV.
 * \param data_ptr pointer to variable where the value is read.
 * \return pointer length of TLV 4 if success. 0 means TLV not found or does not have any data.
 * Any other value indicates that TLV is not as expected.
 */
#define thread_diagcop_tlv_data_get_uint64(ptr,length,type,data) thread_meshcop_tlv_data_get_uint64(ptr,length,type,data)


#endif /* NANOSTACK_SOURCE_6LOWPAN_THREAD_THREAD_DIAGCOP_LIB_H_ */
