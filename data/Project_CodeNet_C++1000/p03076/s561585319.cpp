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

  int32_t max_rest = INT32_MIN;
  int32_t time = 0;
  for (int32_t i = 0; i < 5; ++i) {
    int32_t a;
    cin >> a;
    int32_t rest = 10 - a % 10;
    if (rest == 10) {
      rest = 0;
    }
    max_rest = max(rest, max_rest);
    const int32_t rounded = (a % 10 == 0) ? a : ((a / 10) + 1) * 10;
    time += rounded;
  }
  time -= max_rest;
  cout << time << endl;

  return 0;
}
