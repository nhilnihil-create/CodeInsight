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

  string S, T;
  cin >> S >> T;
  const int64_t N = static_cast<int64_t>(S.length());
  vector<char> from_s_to_t(256, 0);
  vector<char> from_t_to_s(256, 0);
  bool is_okay = true;
  for (int64_t i = 0; i < N; ++i) {
    const char ch_s = S.c_str()[i];
    const char ch_t = T.c_str()[i];
    if ((from_s_to_t[ch_s] != 0 && from_s_to_t[ch_s] != ch_t) ||
        (from_t_to_s[ch_t] != 0 && from_t_to_s[ch_t] != ch_s)) {
      is_okay = false;
    } else {
      from_s_to_t[ch_s] = ch_t;
      from_t_to_s[ch_t] = ch_s;
    }
  }
  if (is_okay) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
