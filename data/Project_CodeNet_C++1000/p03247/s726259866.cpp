#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> X(N), Y(N);
  for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

  for (int i = 0; i < N; ++i) {
    if ((X[i] + Y[i] & 1) != (X[0] + Y[0] & 1)) {
      cout << -1 << endl;
      return 0;
    }
  }

  int special = 0;

  if (~X[0] + Y[0] & 1) {
    special = 1;
    for (int i = 0; i < N; ++i) ++X[i];
  }

  cout << 31 + special << endl;
  for (int i = 0; i < 31; ++i) cout << (1 << i) << " \n"[i + 1 == 31 + special];
  if (special) cout << 1 << endl;

  for (int i = 0; i < N; ++i) {
    int u = X[i] + Y[i];
    int v = X[i] - Y[i];
    vector<int> x(31); {
      for (int j = 0; j < 31; ++j) {
        int tu = (1LL << 31) - 1 + u >> 1;
        int tv = (1LL << 31) - 1 + v >> 1;
        x[j] += (tu >> j & 1) * 2 + (tv >> j & 1);
      }
    }
    string ans;
    for (int i = 0; i < 31; ++i) ans += "LDUR"[x[i]];
    if (special) ans += "L";
    cout << ans << endl;
  }

  return 0;
}
