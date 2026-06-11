#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c;
  cin >> a >> b >> c;

  if (a == b) cout << c << '\n';
  else if (b == c) cout << a << '\n';
  else cout << b << '\n';

  return (0);
}
