#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmax(T &a, T b) { /* {{{ */
  if (a < b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int main() {
  int N, NC;
  cin >> N >> NC;
  vector<vector<int>> U(30, vector<int>(100005));
  for (int i = 0; i < N; i++) {
    int s, t, c;
    cin >> s >> t >> c;
    c--;
    for (int i = s; i <= t; i++) {
      U[c][i] = 1;
    }
  }
  int ans = 0;
  for (int t = 0; t <= 100000; t++) {
    int cnt = 0;
    for (int i = 0; i < 30; i++) {
      if (U[i][t]) cnt++;
    }
    chmax(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
