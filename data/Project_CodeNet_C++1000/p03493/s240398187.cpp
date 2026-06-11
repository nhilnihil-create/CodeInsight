#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int ans = 0;
  for (auto c : s) if (c == '1') ++ans;

  cout << ans << '\n';

  return (0);
}
