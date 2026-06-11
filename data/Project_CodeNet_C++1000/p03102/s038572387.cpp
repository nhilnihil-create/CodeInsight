#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m, c;
  cin >> n >> m >> c;

  int b[m];
  int a[n][m];

  for (int i = 0; i < m; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j) sum += a[i][j] * b[j];
    if (sum + c > 0) ++ans;
  }

  cout << ans << '\n';

  return (0);
}