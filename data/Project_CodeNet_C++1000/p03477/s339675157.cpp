#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int l = a + b, r = c + d;
  if (l > r) cout << "Left\n";
  else if (l < r) cout << "Right\n";
  else cout << "Balanced\n";

  return (0);
}
