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

  string S;
  cin >> S;
  const int64_t length = static_cast<int64_t>(S.length());
  int64_t black_count = 0;
  int64_t total_count = 0;
  for (int64_t i = 0; i < length; ++i) {
    if (S.c_str()[i] == 'W') {
      total_count += black_count;
    } else {
      ++black_count;
    }
  }
  cout << total_count << endl;

  return 0;
}
