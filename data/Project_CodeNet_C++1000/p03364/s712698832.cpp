#include <cstddef>
#include <cstdint>
#include <vector>

using u64 = std::uint_fast64_t;

template <u64 Modulus, u64 BaseX, u64 BaseY> class rolling_hash_2d {
  std::vector<std::vector<u64>> prefix;
  std::vector<u64> power_x, power_y;

public:
  rolling_hash_2d(const std::vector<std::vector<u64>> &table)
      : prefix(), power_x(), power_y() {
    const std::size_t h = table.size();
    const std::size_t w = table.empty() ? 0 : table.front().size();
    prefix.resize(h + 1, std::vector<u64>(w + 1, 0));
    for (std::size_t i = 0; i != h; ++i) {
      for (std::size_t j = 0; j != w; ++j) {
        prefix[i + 1][j + 1] =
            (Modulus - prefix[i][j] * (BaseX * BaseY) +
             prefix[i][j + 1] * BaseX + prefix[i + 1][j] * BaseY + table[i][j]);
      }
    }
    power_x.resize(h + 1);
    power_x[0] = 1;
    for (std::size_t i = 0; i != h; ++i) {
      power_x[i + 1] = power_x[i] * BaseX;
    }
    power_y.resize(w + 1);
    power_y[0] = 1;
    for (std::size_t i = 0; i != w; ++i) {
      power_y[i + 1] = power_y[i] * BaseY;
    }
  }
  u64 operator()(const std::size_t l, const std::size_t d, const std::size_t r,
                 const std::size_t u) const {
    return (prefix[l][d] * (power_x[r - l] * power_y[u - d]) + Modulus -
            prefix[l][u] * power_x[r - l] + Modulus -
            prefix[r][d] * power_y[u - d] + prefix[r][u]);
  }
};

#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<u64>> s(n * 2, std::vector<u64>(n * 2)), t = s;
  for (int i = 0; i != n; ++i) {
    char c;
    for (int j = 0; j != n; ++j) {
      std::cin >> c;
      const u64 v = c - 'a';
      s[i][j] = v;
      s[i][n + j] = v;
      s[n + i][j] = v;
      s[n + i][n + j] = v;
      t[j][i] = v;
      t[j][n + i] = v;
      t[n + j][i] = v;
      t[n + j][n + i] = v;
    }
  }

  static constexpr u64 Modulus = 1000000007;
  static constexpr u64 BaseX = 25254841;
  static constexpr u64 BaseY = 75628891;

  const rolling_hash_2d<Modulus, BaseX, BaseY> sh(s), th(t);

  int ans = 0;

  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != n; ++j) {
      if (sh(i, j, n + i, n + j) == th(j, i, n + j, n + i)) {
        ++ans;
      }
    }
  }

  std::cout << ans << std::endl;
}
