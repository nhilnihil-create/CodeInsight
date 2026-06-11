#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  if (n & 1) cout << 2*n << '\n';
  else cout << n << '\n';

  return (0);
}
