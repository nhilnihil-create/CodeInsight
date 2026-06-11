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

  int64_t N;
  cin >> N;
  int64_t result = 0;
  int64_t top = 0;
  for (int64_t i = 0; i < N; ++i) {
    int64_t h;
    cin >> h;
    if (h > top) {
      result += h - top;
    }
    top = h;
  }
  cout << result << endl;
  return 0;
}
