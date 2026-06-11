/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  constexpr int64_t kMax = 1e5L;
  const int64_t kUpper = static_cast<int64_t>(sqrt(static_cast<double>(kMax)));
  vector<bool> is_prime(kMax + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int64_t i = 4; i <= kMax; i += 2) {
    is_prime[i] = false;
  }
  for (int64_t p = 3; p <= kUpper; p += 2) {
    if (is_prime[p]) {
      for (int64_t j = p * 2; j <= kMax; j += p) {
        is_prime[j] = false;
      }
    }
  }

  vector<int64_t> S(kMax + 1);
  S[0] = 0;
  int64_t count = 0;
  for (int64_t j = 1; j <= kMax; j += 2) {
    if (is_prime[j] && is_prime[(j + 1) / 2]) {
      ++count;
    }
    S[j] = count;
  }

  int64_t Q;
  cin >> Q;
  for (int64_t i = 0; i < Q; ++i) {
    int64_t l, r;
    cin >> l >> r;
    cout << S[r] - S[max(l - 2, 0L)] << endl;
  }
  return 0;
}
