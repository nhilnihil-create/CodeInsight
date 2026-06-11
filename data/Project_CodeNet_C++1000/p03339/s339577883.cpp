#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmin(T &a, T b) { /* {{{ */
  if (a > b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> cnt_e(N + 1);
  for (int i = 0; i < N; i++) {
    cnt_e[i + 1] = cnt_e[i];
    if (S[i] == 'E') cnt_e[i + 1]++;
  }
  int ans = 1e9;
  for (int i = 0; i < N; i++) {
    int left_w = 0;
    if (i > 0) {
      left_w = i - cnt_e[i];
    }
    int right_e = 0;
    if (i < N - 1) {
      right_e = cnt_e[N] - cnt_e[i + 1];
    }
    chmin(ans, left_w + right_e);
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
