#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c;
  cin >> a >> b >> c;

  cout << max({a, b, c}) - min({a, b, c}) << '\n';

  return (0);
}
