/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t K, A, B;
  cin >> K >> A >> B;
  const int64_t d = B - A;
  int64_t result = 0;
  if (d <= 0 || K <= A - 1) {
    result = 1 + K;
  } else {
    int64_t y = (K - A + 1) / 2L;
    int64_t x = K - 2L * y;
    // cerr << x << ", " << y << endl;
    if (y >= 0 && x >= 0) {
      result = max(1 + K, 1 + x + y * (B - A));
    } else {
      result = 1 + K;
    }
  }
  cout << result << endl;
  return 0;
}
