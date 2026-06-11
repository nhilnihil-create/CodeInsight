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

  int32_t N, T, A;
  cin >> N >> T >> A;
  int32_t min = INT32_MAX;
  int32_t result = -1;
  for (int32_t i = 0; i < N; ++i) {
    int32_t H;
    cin >> H;
    const int32_t evaluate = abs(1000 * (T - A) - 6 * H);
    if (evaluate < min) {
      result = i + 1;
      min = evaluate;
    }
  }
  cout << result << endl;
  return 0;
}
