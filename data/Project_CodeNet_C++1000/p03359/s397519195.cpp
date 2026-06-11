#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;

  if (b >= a) cout << a << '\n';
  else cout << a-1 << '\n';

  return (0);
}
