// Project FPGA-TFHE
// https://github.com/rval735/FPGA-TFHE
//
// Based on code from project
// https://github.com/tfhe/tfhe/
//
//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.

#ifndef FFTTABLES_HPP
#define FFTTABLES_HPP

#include <ap_fixed.h>
#include <ap_int.h>
#include  <cstdint>
/// https://docs.xilinx.com/r/en-US/ug1399-vitis-hls/C-Arbitrary-Precision-Fixed-Point-Types
/// In this example the Vitis HLS ap_fixed type is used to define an 18-bit variable
/// with 6 bits representing the numbers above the decimal point and 12-bits representing
/// the value below the decimal point. The variable is specified as signed, the
/// quantization mode is set to round to plus infinity and the default wrap-around mode
/// is used for overflow.
/// ap_fixed<18,6,AP_RND > my_type;
#define AP_TOTAL 16
#define AP_DECIMAL 2

//typedef ap_fixed<128, 40, AP_RND_ZERO, AP_SAT_ZERO> APDouble;
//typedef ap_fixed<64, 53, AP_RND_ZERO, AP_SAT_ZERO> APDouble; // like the std::double
//typedef ap_uint<64> APUInt64;
//typedef ap_int<64> APInt64;
//typedef ap_uint<32> APUInt32;
//typedef ap_int<32> APInt32;
//typedef APInt32 APTorus32;

typedef double APDouble;
typedef uint64_t APUInt64;
typedef int64_t APInt64;
typedef uint32_t APUInt32;
typedef int32_t APInt32;
typedef APInt32 APTorus32;

// Private data structure
struct FFTTables
{
	constexpr static int FFTSize = 2048;
	APUInt64 bitReversed[FFTSize];
	APDouble trigTables[(FFTSize - 4) * 2];

	FFTTables(bool isInverse);
};

APDouble accurateSin(APUInt64 i, APUInt64 n);
APInt32 floorLog2(APUInt64 n);
APUInt64 reverseBits(APUInt64 x, APUInt32 n);

void fftForward(APDouble real[FFTTables::FFTSize], APDouble imag[FFTTables::FFTSize]);
void fftInverse(APDouble real[FFTTables::FFTSize], APDouble imag[FFTTables::FFTSize]);

#endif // FFTTABLES_HPP
