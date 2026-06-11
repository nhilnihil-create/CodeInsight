#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  char a, b;
  cin >> a >> b;

  if (a < b) cout << "<\n";
  else if (a > b) cout << ">\n";
  else cout << "=\n";

  return (0);
}
