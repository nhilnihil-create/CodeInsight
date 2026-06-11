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
  int N;
  cin >> N;
  vector<vector<int>> F(N, vector<int>(10));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> F[i][j];
    }
  }
  vector<vector<int>> P(N, vector<int>(11));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 10; j++) {
      cin >> P[i][j];
    }
  }
  int ans = -1e9 - 10;
  for (int bits = 1; bits < (1 << 10); bits++) {
    int a = 0;
    for (int i = 0; i < N; i++) {
      int cnt = 0;
      for (int j = 0; j < 10; j++) {
        if (F[i][j] && (bits & (1 << j))) cnt++;
      }
      a += P[i][cnt];
    }
    chmax(ans, a);
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
