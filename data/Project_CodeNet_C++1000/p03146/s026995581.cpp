#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll s;
  cin >> s;

  set<ll> appear;
  int ans = 1;

  while (1) {
    if (appear.count(s)) break;
    appear.emplace(s);

    if (s & 1) s = 3 * s + 1;
    else s /= 2;

    ++ans;
  }

  cout << ans << '\n';

  return (0);
}
