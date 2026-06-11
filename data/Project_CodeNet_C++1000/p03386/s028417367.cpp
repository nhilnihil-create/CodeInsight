/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

bool IsSquaredValue(int32_t n) {
  const int32_t a = static_cast<int32_t>(sqrt(n));
  return (a * a == n);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t A, B, K;
  cin >> A >> B >> K;
  for (int32_t i = A; i <= B; ++i) {
    if ((i >= A && i < A + K) || (i >= B - K + 1 && i <= B)) {
      cout << i << endl;
    }
  }
  return 0;
}
