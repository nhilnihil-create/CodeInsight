#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, a;
  cin >> n >> a;

  if (n % 500 <= a) cout << "Yes\n";
  else cout << "No\n";

  return (0);
}
