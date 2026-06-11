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

  int32_t c[3][3];
  for (int32_t i = 0; i < 3; ++i) {
    for (int32_t j = 0; j < 3; ++j) {
      cin >> c[i][j];
    }
  }
  const int32_t d1 = c[1][0] - c[0][0];
  const int32_t d2 = c[2][0] - c[0][0];
  bool is_okay = true;
  for (int32_t j = 1; j <= 2; ++j) {
    if (c[1][j] - c[0][j] != d1) {
      is_okay = false;
    }
    if (c[2][j] - c[0][j] != d2) {
      is_okay = false;
    }
  }
  if (is_okay) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
