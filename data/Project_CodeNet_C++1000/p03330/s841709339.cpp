#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, C;
  int d[30][30], pre[3][30], c[505][505];
  cin >> n >> C;
  rep(i, C) rep(j, C) cin >> d[i][j];
  rep(i, n) rep(j, n) cin >> c[i][j], c[i][j]--;

  rep(i, n) rep(j, n) rep(col, C) pre[(i + j) % 3][col] += d[c[i][j]][col];

  int ans = 1 << 30;
  rep(c0, C) rep(c1, C) rep(c2, C) if (!(c0 == c1 || c0 == c2 || c1 == c2))
      ans = min(ans, pre[0][c0] + pre[1][c1] + pre[2][c2]);

  cout << ans << endl;
  return 0;
}