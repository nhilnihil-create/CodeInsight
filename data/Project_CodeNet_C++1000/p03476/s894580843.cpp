/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

std::vector<bool> GeneratePrimeTable(const int64_t max_value) {
  // 素数の真偽表を返却する。
  // エラトステネスの篩(Sieve of Eratosthenes). O(n * log(log(n)))
  const int64_t upper_limit =
      static_cast<int64_t>(sqrt(static_cast<double>(max_value)));
  std::vector<bool> is_prime(max_value + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int64_t i = 4; i <= max_value; i += 2) {
    is_prime[i] = false;
  }
  for (int64_t p = 3; p <= upper_limit; p += 2) {
    if (is_prime[p]) {
      for (int64_t i = p * 2; i <= max_value; i += p) {
        is_prime[i] = false;
      }
    }
  }
  return is_prime;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  constexpr int64_t kMax = 1e5L;
  vector<bool> is_prime = GeneratePrimeTable(kMax);
  vector<int64_t> counts(kMax + 2, 0);
  for (int64_t i = 1; i <= kMax; i += 2) {
    if (is_prime[i]) {
      if (is_prime[(i + 1) / 2]) {
        counts[i] = 1;
      }
    }
  }
  for (int64_t i = 1; i <= kMax; ++i) {
    counts[i] += counts[i - 1];
  }
  int64_t Q;
  cin >> Q;
  for (int64_t q = 0; q < Q; ++q) {
    int64_t l, r;
    cin >> l >> r;
    cout << counts[r] - counts[l - 1] << endl;
  }
  return 0;
}
