#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

// lib/greater_by.hpp
#ifndef GREATER_BY_HPP
#define GREATER_BY_HPP


/*
usage:

std::sort(a.begin(), a.end(), tools::greater_by([](int a_i) { return std::abs(x); }));
*/

namespace tools {
  template <class T, class R>
  class greater_by {
  private:
    ::std::function<R(T)> selector;

  public:
    greater_by(const ::std::function<R(T)>& selector) : selector(selector) {
    }

    bool operator()(const T& x, const T& y) const {
      static const std::greater<R> comp;
      return comp(selector(x), selector(y));
    }

    using first_argument_type = T;
    using second_argument_type = T;
    using result_type = bool;
  };
}

#endif

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

class sushi {
public:
  i64 type;
  i64 score;

  friend std::istream& operator>>(std::istream& is, sushi& self) {
    return is >> self.type >> self.score;
  }
};

int main() {
  i64 N, K;
  std::cin >> N >> K;
  std::vector<sushi> sushis;
  tools::read(sushis, N);

  std::sort(sushis.begin(), sushis.end(), tools::greater_by<sushi, i64>([](const sushi& sushi) { return sushi.score; }));

  std::vector<i64> nuisances;
  std::vector<i64> talents;
  i64 x = 0;
  {
    std::unordered_set<i64> found;
    for (auto it = sushis.begin(); it != sushis.begin() + K; ++it) {
      if (found.find(it->type) == found.end()) {
        found.insert(it->type);
        ++x;
      } else {
        nuisances.push_back(it->score);
      }
    }
    for (auto it = sushis.begin() + K; it != sushis.end(); ++it) {
      if (found.find(it->type) == found.end()) {
        found.insert(it->type);
        talents.push_back(it->score);
      }
    }
  }
  std::reverse(nuisances.begin(), nuisances.end());

  i64 base_score = std::accumulate(sushis.begin(), sushis.begin() + K, static_cast<i64>(0), [](const i64& sum, const sushi& sushi) { return sum + sushi.score; });
  i64 answer = base_score + x * x;
  for (i64 i = 0; i < std::min<i64>(nuisances.size(), talents.size()); ++i) {
    base_score += talents[i] - nuisances[i];
    ++x;
    answer = std::max(answer, base_score + x * x);
  }

  std::cout << answer << std::endl;
  return 0;
}