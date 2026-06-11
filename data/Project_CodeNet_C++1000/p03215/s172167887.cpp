#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


typedef ::std::int_fast64_t i64;
typedef ::std::uint_fast64_t u64;
typedef ::std::int_fast32_t i32;
typedef ::std::uint_fast32_t u32;

namespace tools {
  template <typename T>
  void read(::std::istream& is, ::std::vector<T>& vector, const typename ::std::vector<T>::size_type size) {
    vector.reserve(size);
    ::std::copy_n(::std::istream_iterator<T>(is), size, ::std::back_inserter(vector));
  }
  template <typename T>
  void read(::std::vector<T>& vector, const typename ::std::vector<T>::size_type size) {
    ::tools::read(::std::cin, vector, size);
  }

  template <typename T, ::std::size_t N>
  void read(::std::istream& is, ::std::array<T, N>& array) {
    ::std::copy_n(std::istream_iterator<T>(is), N, array.begin());
  }
  template <typename T, ::std::size_t N>
  void read(::std::array<T, N>& array) {
    ::tools::read(::std::cin, array);
  }
}

#endif

// main.cpp

int main() {
  i64 N, K;
  std::cin >> N >> K;
  std::vector<i64> a;
  tools::read(a, N);
  std::vector<i64> b({0});
  std::partial_sum(a.begin(), a.end(), std::back_inserter(b));
  std::vector<i64> c;
  for (i64 i = 0; i < N; ++i) {
    for (i64 j = i + 1; j <= N; ++j) {
      c.push_back(b[j] - b[i]);
    }
  }
  i64 answer = 0;
  for (i64 shift = 63; shift >= 0; --shift) {
    std::vector<i64> d;
    for (const i64& c_i : c) {
      if ((c_i >> shift) & 1) {
        d.push_back(c_i);
      }
    }
    if (static_cast<i64>(d.size()) >= K) {
      answer |= static_cast<i64>(1) << shift;
      c = std::move(d);
    }
  }

  std::cout << answer << std::endl;
  return 0;
}