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

  string s;
  cin >> s;
  const int64_t L = static_cast<int64_t>(s.length());
  int64_t result = 0;
  int64_t count = 0;
  int64_t i = 0;
  while (i < L) {
    if (s.substr(i, 1) == "A") {
      ++count;
      ++i;
    } else if (s.substr(i, 2) == "BC") {
      result += count;
      i += 2;
    } else {
      count = 0;
      ++i;
    }
  }
  cout << result << endl;
  return 0;
}
