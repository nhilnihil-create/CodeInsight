#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;

  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a, a+n);
  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    if (x - a[i] < 0) break;
    else x -= a[i];

    ++cnt;
  }

  if (cnt == n) {
    if (x > 0) cout << n-1 << '\n';
    else cout << n << '\n';
  } else cout << cnt << '\n';

  return (0);
}
