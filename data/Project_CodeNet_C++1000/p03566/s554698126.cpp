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
  cin >> N;
  vector<int> T(N + 2), TS(N + 2), V(N + 2);
  for (int i = 1; i <= N; i++) {
    cin >> T[i];
    TS[i] = TS[i - 1] + T[i];
  }
  for (int i = 1; i <= N; i++) cin >> V[i];
  vector<double> max_v(40005);
  for (int i = 1; i <= N; i++) {
    for (int t = TS[i - 1] * 2; t <= TS[i] * 2; t++) {
      max_v[t] = V[i];
    }
  }
  for (int i = 0; i <= 40000; i++) {
    double t = (double)i / 2;
    for (int j = 0; j <= N; j++) {
      chmin(max_v[i], V[j] + abs(t - TS[j]));
      chmin(max_v[i], V[j + 1] + abs(t - TS[j]));
    }
  }
  double ans = 0;
  for (int i = 0; i < 40000; i++) {
    ans += (max_v[i] + max_v[i + 1]) / 4;
  }

  cout << fixed << setprecision(10);
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
