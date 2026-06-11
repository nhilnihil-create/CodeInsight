#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

ll f[101][11], p[101][11];
int main() {
  int n;
  cin >> n;
  rep(i, n) rep(j, 10) cin >> f[i][j];
  rep(i, n) rep(j, 11) cin >> p[i][j];

  ll ans = -INF;
  for (int b = 1; b < (1 << 10); b++) {
    ll t = 0;
    for (int i = 0; i < n; i++) {
      ll c = 0;
      for (int j = 0; j < 10; j++)
        if ((b & 1 << j) && f[i][j]) c++;
      t += p[i][c];
    }
    ans = max(ans, t);
  }
  cout << ans << endl;
  return 0;
}
