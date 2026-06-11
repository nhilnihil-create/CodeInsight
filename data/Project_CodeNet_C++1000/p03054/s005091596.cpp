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
  i64 H, W, N, s_r, s_c;
  std::string S, T;
  std::cin >> H >> W >> N >> s_r >> s_c >> S >> T;

  {
    i64 x = s_c;
    for (i64 i = 0; i < N; ++i) {
      if (S[i] == 'L') {
        --x;
      }
      if (x < 1) {
        goto TAKAHASHI;
      }
      if (T[i] == 'R') {
        x = std::min<i64>(x + 1, W);
      }
    }
  }
  {
    i64 x = s_c;
    for (i64 i = 0; i < N; ++i) {
      if (S[i] == 'R') {
        ++x;
      }
      if (x > W) {
        goto TAKAHASHI;
      }
      if (T[i] == 'L') {
        x = std::max<i64>(x - 1, 1);
      }
    }
  }
  {
    i64 y = s_r;
    for (i64 i = 0; i < N; ++i) {
      if (S[i] == 'U') {
        --y;
      }
      if (y < 1) {
        goto TAKAHASHI;
      }
      if (T[i] == 'D') {
        y = std::min<i64>(y + 1, H);
      }
    }
  }
  {
    i64 y = s_r;
    for (i64 i = 0; i < N; ++i) {
      if (S[i] == 'D') {
        ++y;
      }
      if (y > H) {
        goto TAKAHASHI;
      }
      if (T[i] == 'U') {
        y = std::max<i64>(y - 1, 1);
      }
    }
  }

  std::cout << "YES" << std::endl;
  return 0;

TAKAHASHI:
  std::cout << "NO" << std::endl;
  return 0;
}