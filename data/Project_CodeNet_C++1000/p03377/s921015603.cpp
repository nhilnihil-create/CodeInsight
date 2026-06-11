#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, x;
  cin >> a >> b >> x;

  if (a > x) cout << "NO\n";
  else if (a + b >= x) cout << "YES\n";
  else cout << "NO\n";

  return (0);
}
