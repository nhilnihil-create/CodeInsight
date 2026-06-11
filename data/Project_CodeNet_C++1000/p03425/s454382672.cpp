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
  vector<int64_t> count(5, 0);
  for (int64_t i = 0; i < N; ++i) {
    string s;
    cin >> s;
    if (s[0] == 'M') {
      ++count[0];
    } else if (s[0] == 'A') {
      ++count[1];
    } else if (s[0] == 'R') {
      ++count[2];
    } else if (s[0] == 'C') {
      ++count[3];
    } else if (s[0] == 'H') {
      ++count[4];
    } else {
      // DO NOTHING
    }
  }
  int64_t result = 0;
  for (int64_t i = 0; i < 5; ++i) {
    for (int64_t j = i + 1; j < 5; ++j) {
      for (int64_t k = j + 1; k < 5; ++k) {
        result += count[i] * count[j] * count[k];
      }
    }
  }
  cout << result << endl;
  return 0;
}
