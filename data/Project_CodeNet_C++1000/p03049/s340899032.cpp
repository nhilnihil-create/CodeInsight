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

  int64_t N;
  cin >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  int64_t b_only = 0;
  int64_t a_only = 0;
  int64_t b_and_a = 0;
  int64_t result = 0;
  for (int64_t i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int64_t j = 0; j <= static_cast<int64_t>(s.length()) - 2; ++j) {
      if (s.c_str()[j] == 'A' && s.c_str()[j + 1] == 'B') {
        ++result;
      }
    }
    if (s.c_str()[0] == 'B' && s.c_str()[static_cast<int64_t>(s.length()) - 1] == 'A') {
      ++b_and_a;
    } else if (s.c_str()[0] == 'B') {
      ++b_only;
    } else if (s.c_str()[static_cast<int64_t>(s.length()) - 1] == 'A') {
      ++a_only;
    }
  }
  result += max(b_and_a - 1, static_cast<int64_t>(0));
  if (b_and_a > 0) {
    if (b_only > 0) {
      ++result;
      --b_only;
    }
    if (a_only > 0) {
      ++result;
      --a_only;
    }
  }
  result += min(b_only, a_only);
  cout << result << endl;
  return 0;
}
