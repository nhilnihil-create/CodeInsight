#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if ((abs(b - a) <= d && abs(c - b) <= d) || (abs(a - c) <= d)) cout << "Yes\n";
  else cout << "No\n";

  return (0);
}
