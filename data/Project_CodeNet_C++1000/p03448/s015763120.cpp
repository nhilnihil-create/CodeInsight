/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t A, B, C, X;
  cin >> A >> B >> C >> X;
  int32_t result = 0;
  for (int32_t a = 0; a <= A; ++a) {
    for (int32_t b = 0; b <= B; ++b) {
      const int32_t residual = X - a * 500 - b * 100;
      const int32_t temp = residual / 50;
      if (residual % 50 == 0 && temp >= 0 && temp <= C) {
        result++;
      }
    }
  }
  cout << result << endl;

  return 0;
}
