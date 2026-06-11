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
  i64 N;
  std::cin >> N;
  std::vector<std::vector<i64>> graph(N);
  for (i64 i = 0; i < N - 1; ++i) {
    i64 a_i, b_i;
    std::cin >> a_i >> b_i;
    graph[a_i - 1].push_back(b_i - 1);
    graph[b_i - 1].push_back(a_i - 1);
  }
  std::vector<i64> c;
  tools::read(c, N);

  std::sort(c.begin(), c.end(), std::greater<i64>());
  i64 M = 0;
  std::vector<i64> d(N);
  std::vector<bool> visited(N, false);
  std::function<void(i64)> dfs;
  dfs = [&](const i64 from) {
    visited[from] = true;
    for (const i64& to : graph[from]) {
      if (!visited[to]) {
        dfs(to);
      }
    }
    M += c.back();
    d[from] = c.back();
    c.pop_back();
  };
  dfs(0);
  M -= *std::max_element(c.begin(), c.end());

  std::cout << M << std::endl;
  std::string delimiter = "";
  for (const i64& d_i : d) {
    std::cout << delimiter << d_i;
    delimiter = " ";
  }
  std::cout << std::endl;
  return 0;
}