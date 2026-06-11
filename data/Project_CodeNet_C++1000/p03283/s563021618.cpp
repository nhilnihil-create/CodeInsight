#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, m, q, l, r, ans;
  cin >> n >> m >> q;
  ll p[501][501];
  memset(p, 0, sizeof(p));

  rep(i, m) {
    cin >> l >> r;
    p[l][r]++;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) p[i][j] += p[i][j - 1];
    for (int j = 1; j <= n; ++j) p[i][j] += p[i - 1][j];
  }

  rep(i, q) {
    cin >> l >> r;
    ans = p[r][r] + p[l - 1][l - 1] - p[l - 1][r] - p[r][l - 1];
    cout << ans << endl;
  }
}