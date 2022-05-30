/**
 *
 * @copyright &copy; 2010 - 2022, Fraunhofer-Gesellschaft zur Foerderung der angewandten Forschung e.V.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * We kindly request you to use one or more of the following phrases to refer to
 * foxBMS in your hardware, software, documentation or advertising materials:
 *
 * - &Prime;This product uses parts of foxBMS&reg;&Prime;
 * - &Prime;This product includes parts of foxBMS&reg;&Prime;
 * - &Prime;This product is derived from foxBMS&reg;&Prime;
 *
 */

/**
 * @file    diag_cbs_voltage.c
 * @author  foxBMS Team
 * @date    2021-02-17 (date of creation)
 * @updated 2022-05-30 (date of last update)
 * @version v1.3.0
 * @ingroup ENGINE
 * @prefix  DIAG
 *
 * @brief   Diagnosis driver implementation
 * @details TODO
 */

/*========== Includes =======================================================*/
#include "diag_cbs.h"

/*========== Macros and Definitions =========================================*/

/*========== Static Constant and Variable Definitions =======================*/

/*========== Extern Constant and Variable Definitions =======================*/

/*========== Static Function Prototypes =====================================*/

/*========== Static Function Implementations ================================*/

/*========== Extern Function Implementations ================================*/
extern void DIAG_ErrorOvervoltage(
    DIAG_ID_e ch_id,
    DIAG_EVENT_e event,
    const DIAG_DATABASE_SHIM_s *const kpkDiagShim,
    uint32_t stringNumber) {
    FAS_ASSERT(ch_id < DIAG_ID_MAX);
    FAS_ASSERT((event == DIAG_EVENT_OK) || (event == DIAG_EVENT_NOT_OK) || (event == DIAG_EVENT_RESET));
    FAS_ASSERT(kpkDiagShim != NULL_PTR);
    FAS_ASSERT(stringNumber < BS_NR_OF_STRINGS);

    if (ch_id == DIAG_ID_CELLVOLTAGE_OVERVOLTAGE_MSL) {
        if (event == DIAG_EVENT_RESET) {
            kpkDiagShim->pTableMsl->overVoltage[stringNumber] = 0;
        }
        if (event == DIAG_EVENT_NOT_OK) {
            kpkDiagShim->pTableMsl->overVoltage[stringNumber] = 1;
        }
    } else if (ch_id == DIAG_ID_CELLVOLTAGE_OVERVOLTAGE_RSL) {
        if (event == DIAG_EVENT_RESET) {
            kpkDiagShim->pTableRsl->overVoltage[stringNumber] = 0;
        }
        if (event == DIAG_EVENT_NOT_OK) {
            kpkDiagShim->pTableRsl->overVoltage[stringNumber] = 1;
        }
    } else if (ch_id == DIAG_ID_CELLVOLTAGE_OVERVOLTAGE_MOL) {
        if (event == DIAG_EVENT_RESET) {
            kpkDiagShim->pTableMol->overVoltage[stringNumber] = 0;
        }
        if (event == DIAG_EVENT_NOT_OK) {
            kpkDiagShim->pTableMol->overVoltage[stringNumber] = 1;
        }
    }
}

extern void DIAG_ErrorUndervoltage(
    DIAG_ID_e ch_id,
    DIAG_EVENT_e event,
    const DIAG_DATABASE_SHIM_s *const kpkDiagShim,
    uint32_t stringNumber) {
    FAS_ASSERT(ch_id < DIAG_ID_MAX);
    FAS_ASSERT((event == DIAG_EVENT_OK) || (event == DIAG_EVENT_NOT_OK) || (event == DIAG_EVENT_RESET));
    FAS_ASSERT(kpkDiagShim != NULL_PTR);
    FAS_ASSERT(stringNumber < BS_NR_OF_STRINGS);

    if (ch_id == DIAG_ID_CELLVOLTAGE_UNDERVOLTAGE_MSL) {
        if (event == DIAG_EVENT_RESET) {
            kpkDiagShim->pTableMsl->underVoltage[stringNumber] = 0;
        }
        if (event == DIAG_EVENT_NOT_OK) {
            kpkDiagShim->pTableMsl->underVoltage[stringNumber] = 1;
        }
    } else if (ch_id == DIAG_ID_CELLVOLTAGE_UNDERVOLTAGE_RSL) {
        if (event == DIAG_EVENT_RESET) {
            kpkDiagShim->pTableRsl->underVoltage[stringNumber] = 0;
        }
        if (event == DIAG_EVENT_NOT_OK) {
            kpkDiagShim->pTableRsl->underVoltage[stringNumber] = 1;
        }
    } else if (ch_id == DIAG_ID_CELLVOLTAGE_UNDERVOLTAGE_MOL) {
        if (event == DIAG_EVENT_RESET) {
            kpkDiagShim->pTableMol->underVoltage[stringNumber] = 0;
        }
        if (event == DIAG_EVENT_NOT_OK) {
            kpkDiagShim->pTableMol->underVoltage[stringNumber] = 1;
        }
    }
}

extern void DIAG_ErrorHighVoltageMeasurement(
    DIAG_ID_e ch_id,
    DIAG_EVENT_e event,
    const DIAG_DATABASE_SHIM_s *const kpkDiagShim,
    uint32_t stringNumber) {
    FAS_ASSERT(ch_id < DIAG_ID_MAX);
    FAS_ASSERT((event == DIAG_EVENT_OK) || (event == DIAG_EVENT_NOT_OK) || (event == DIAG_EVENT_RESET));
    FAS_ASSERT(kpkDiagShim != NULL_PTR);
    FAS_ASSERT(stringNumber < BS_NR_OF_STRINGS);

    switch (ch_id) {
        case DIAG_ID_CURRENT_SENSOR_V1_MEASUREMENT_TIMEOUT:
            if (event == DIAG_EVENT_RESET) {
                kpkDiagShim->pTableError->currentSensorTimeoutV1[stringNumber] = 0u;
            } else if (event == DIAG_EVENT_NOT_OK) {
                kpkDiagShim->pTableError->currentSensorTimeoutV1[stringNumber] = 1u;
            } else {
                /* no relevant event, do nothing */
            }
            break;
        case DIAG_ID_CURRENT_SENSOR_V3_MEASUREMENT_TIMEOUT:
            if (event == DIAG_EVENT_RESET) {
                kpkDiagShim->pTableError->currentSensorTimeoutV3[stringNumber] = 0u;
            } else if (event == DIAG_EVENT_NOT_OK) {
                kpkDiagShim->pTableError->currentSensorTimeoutV3[stringNumber] = 1u;
            } else {
                /* no relevant event, do nothing */
            }
            break;

        default:
            FAS_ASSERT(FAS_TRAP);
            break;
    }
}

/*========== Externalized Static Function Implementations (Unit Test) =======*/
