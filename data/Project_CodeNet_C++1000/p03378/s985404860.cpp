#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[101];

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m, x;
  cin >> n >> m >> x;

  for (int i = 0; i < m; ++i) {
    int s;
    cin >> s;

    ++a[s];
  }

  for (int i = 0; i < 100; ++i) a[i+1] += a[i];

  cout << min(a[x], m - a[x]) << '\n';

  return (0);
}
