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
  i64 A, B;
  std::cin >> A >> B;

  std::vector<std::string> s(40);
  for (i64 y = 0; y < 20; ++y) {
    s[y] = std::string(100, '#');
  }
  for (i64 y = 20; y < 40; ++y) {
    s[y] = std::string(100, '.');
  }

  for (i64 i = 0; i < A - 1; ++i) {
    const i64 y = i / 50 * 2;
    const i64 x = i % 50 * 2;
    s[y][x] = '.';
  }
  for (i64 i = 0; i < B - 1; ++i) {
    const i64 y = i / 50 * 2 + 21;
    const i64 x = i % 50 * 2;
    s[y][x] = '#';
  }

  std::cout << 40 << ' ' << 100 << std::endl;
  for (const std::string& s_i : s) {
    std::cout << s_i << std::endl;
  }
  return 0;
}