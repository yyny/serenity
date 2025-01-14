/*
 * Copyright (c) 2021, Matthew Olsson <mattco@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/ByteBuffer.h>
#include <AK/Error.h>
#include <AK/FlyString.h>
#include <LibPDF/ObjectDerivatives.h>

namespace PDF {

class Filter {
public:
    static ErrorOr<ByteBuffer> decode(ReadonlyBytes bytes, FlyString const& encoding_type, RefPtr<DictObject> decode_parms);

private:
    static ErrorOr<ByteBuffer> decode_ascii_hex(ReadonlyBytes bytes);
    static ErrorOr<ByteBuffer> decode_ascii85(ReadonlyBytes bytes);
    static ErrorOr<ByteBuffer> decode_png_prediction(Bytes bytes, int bytes_per_row);
    static ErrorOr<ByteBuffer> decode_lzw(ReadonlyBytes bytes);
    static ErrorOr<ByteBuffer> decode_flate(ReadonlyBytes bytes, int predictor, int columns, int colors, int bits_per_component);
    static ErrorOr<ByteBuffer> decode_run_length(ReadonlyBytes bytes);
    static ErrorOr<ByteBuffer> decode_ccitt(ReadonlyBytes bytes);
    static ErrorOr<ByteBuffer> decode_jbig2(ReadonlyBytes bytes);
    static ErrorOr<ByteBuffer> decode_dct(ReadonlyBytes bytes);
    static ErrorOr<ByteBuffer> decode_jpx(ReadonlyBytes bytes);
    static ErrorOr<ByteBuffer> decode_crypt(ReadonlyBytes bytes);
};

}
