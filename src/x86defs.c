/*
x86defs.c

diStorm3 - Powerful disassembler for X86/AMD64
http://ragestorm.net/distorm/
distorm at gmail dot com
Copyright (C) 2011  Gil Dabah

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/


#include "x86defs.h"
#include "instructions.h"
#include "../include/mnemonics.h"


_InstInfo II_arpl = {INST_MODRM_REQUIRED, I_ARPL, ISC_INTEGER << 3, OT_REG16, OT_RM16};
/*
 * MOVSXD:
 * This is the worst defined instruction ever. It has so many variations.
 * I decided after a third review, to make it like MOVSXD RAX, EAX when there IS a REX.W.
 * Otherwise it will be MOVSXD EAX, EAX, which really zero extends to RAX.
 * Completely ignoring DB 0x66, which is possible by the docs, BTW.
 */
_InstInfo II_movsxd = {INST_MODRM_REQUIRED | INST_PRE_REX | INST_64BITS, I_MOVSXD, ISC_INTEGER << 3, OT_RM32, OT_REG32_64};

_InstInfo II_nop = {INST_FLAGS_NONE, I_NOP, ISC_INTEGER << 3, OT_NONE, OT_NONE};

_InstInfo II_pause = {INST_FLAGS_NONE, I_PAUSE, ISC_INTEGER << 3, OT_NONE, OT_NONE};
