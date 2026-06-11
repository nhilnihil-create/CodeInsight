#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, a, b;
  cin >> n >> a >> b;

  cout << min(b, a * n) << '\n';

  return (0);
}
