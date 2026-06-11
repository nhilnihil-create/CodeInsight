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

  constexpr int32_t kFavorite = 753;
  string S;
  cin >> S;
  int32_t min_val = INT32_MAX;
  const int32_t length = static_cast<int32_t>(S.length());
  for (int32_t i = 0; i <= length - 3; ++i) {
    const int32_t value = stoi(S.substr(i, 3));
    const int32_t delta = abs(value - kFavorite);
    if (delta < min_val) {
      min_val = delta;
    }
  }
  cout << min_val << endl;

  return 0;
}
