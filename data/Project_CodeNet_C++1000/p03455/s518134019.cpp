#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;

  if (a * b % 2) cout << "Odd\n";
  else cout << "Even\n";

  return (0);
}
