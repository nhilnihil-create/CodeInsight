#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int ans = 700;
  for (auto c : s) ans += (c == 'o' ? 100 : 0);

  cout << ans << '\n';

  return (0);
}
