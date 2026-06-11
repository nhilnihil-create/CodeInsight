#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


typedef std::int_fast64_t i64;
typedef std::uint_fast64_t u64;
typedef std::int_fast32_t i32;
typedef std::uint_fast32_t u32;

namespace tools {
  template <typename T>
  void read(std::vector<T>& vector, const typename std::vector<T>::size_type size) {
    vector.reserve(size);
    std::copy_n(std::istream_iterator<T>(std::cin), size, std::back_inserter(vector));
  }

  template <typename T, std::size_t N>
  void read(std::array<T, N>& array) {
    std::copy_n(std::istream_iterator<T>(std::cin), N, array.begin());
  }
}

#endif

// main.cpp

namespace abc078d {
  enum class turn {
    X, Y
  };

  class scene {
  public:
    i64 X, Y, phase;
    abc078d::turn turn;
    scene(const i64 X, const i64 Y, const i64 phase, const abc078d::turn turn) :
      X(X), Y(Y), phase(phase), turn(turn) {
    }
    bool operator==(const scene& other) const {
      if (this->phase != other.phase) return false;
      if (this->phase == 0) {
        return this->X == other.X && this->Y == other.Y;
      } else {
        if (this->turn != other.turn) return false;
        if (this->turn == abc078d::turn::X) {
          return this->Y == other.Y;
        } else {
          return this->X == other.X;
        }
      }
    }
  };
}

namespace std {
  template <>
  struct hash<abc078d::scene> {
    std::size_t operator()(const abc078d::scene& scene) const {
      static std::hash<i64> hash_i64;
      static std::hash<int> hash_int;
      std::size_t result = 17;
      if (scene.phase == 0) {
        result = 31 * result + hash_int(1);
        result = 31 * result + hash_i64(scene.X);
        result = 31 * result + hash_i64(scene.Y);
      } else {
        if (scene.turn == abc078d::turn::X) {
          result = 31 * result + hash_int(2);
          result = 31 * result + hash_i64(scene.Y);
          result = 31 * result + hash_i64(scene.phase);
        } else {
          result = 31 * result + hash_int(3);
          result = 31 * result + hash_i64(scene.X);
          result = 31 * result + hash_i64(scene.phase);
        }
      }
      return result;
    }
  };
}

namespace abc078d {
  class constraint {
  public:
    i64 N;
    std::vector<i64> a;
    constraint(const i64 N, const std::vector<i64>& a) :
      N(N), a(a) {
    }
  };

  i64 minmax(const abc078d::scene scene, const abc078d::constraint& constraint) {
    static std::unordered_map<abc078d::scene, i64> cache;

    if (scene.phase == constraint.N) {
      return std::abs(scene.X - scene.Y);
    }

    const auto it = cache.find(scene);
    if (it != cache.end()) {
      return it->second;
    }

    if (scene.turn == abc078d::turn::X) {
      i64 max = std::numeric_limits<i64>::min();
      for (i64 i = scene.phase + 1; i <= constraint.N; ++i) {
        max = std::max(max, abc078d::minmax(abc078d::scene(constraint.a[i - 1], scene.Y, i, abc078d::turn::Y), constraint));
      }
      cache.insert(std::make_pair(scene, max));
      return max;
    } else {
      i64 min = std::numeric_limits<i64>::max();
      for (i64 i = scene.phase + 1; i <= constraint.N; ++i) {
        min = std::min(min, abc078d::minmax(abc078d::scene(scene.X, constraint.a[i - 1], i, abc078d::turn::X), constraint));
      }
      cache.insert(std::make_pair(scene, min));
      return min;
    }
  }
}

int main() {
  i64 N, Z, W;
  std::cin >> N >> Z >> W;
  std::vector<i64> a;
  tools::read(a, N);

  std::cout << abc078d::minmax(
    abc078d::scene(Z, W, 0, abc078d::turn::X),
    abc078d::constraint(N, a)
  ) << std::endl;
  return 0;
}