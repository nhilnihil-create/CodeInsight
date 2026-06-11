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

  string S, T;
  cin >> S >> T;
  const int64_t L = static_cast<int64_t>(T.length());
  vector<char> from_s_to_t('z' - 'a' + 1, -1);
  vector<char> from_t_to_s('z' - 'a' + 1, -1);
  bool result = true;
  for (int64_t i = 0; i < L; ++i) {
    if (from_s_to_t[S[i] - 'a'] >= 0 && from_s_to_t[S[i] - 'a'] != T[i] - 'a') {
      result = false;
      break;
    }
    if (from_t_to_s[T[i] - 'a'] >= 0 && from_t_to_s[T[i] - 'a'] != S[i] - 'a') {
      result = false;
      break;
    }
    from_s_to_t[S[i] - 'a'] = T[i] - 'a';
    from_t_to_s[T[i] - 'a'] = S[i] - 'a';
  }
  if (result) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
