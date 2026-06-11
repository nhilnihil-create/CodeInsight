#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, k;
  cin >> a >> b >> k;

  set<int> s;
  for (int i = a; i <= min(b, a+k-1); ++i) s.emplace(i);
  for (int i = max(a+k, b-k+1); i <= b; ++i) s.emplace(i);

  for (auto e : s) cout << e << '\n';

  return (0);
}
