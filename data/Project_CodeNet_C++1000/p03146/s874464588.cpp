/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int32_t f(const int32_t n) {
  return (n % 2 == 0) ? n / 2 : 3 * n + 1;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t s;
  cin >> s;
  int32_t value = s;
  int32_t m = -1;
  vector<bool> lookup(1000000 + 1, false);
  lookup[value] = true;
  for (int32_t i = 2; i < 1000002; ++i) {
    value = f(value);
    if (lookup[value]) {
      m = i;
      break;
    } else {
      lookup[value] = true;
    }
  }
  cout << m << endl;

  return 0;
}
