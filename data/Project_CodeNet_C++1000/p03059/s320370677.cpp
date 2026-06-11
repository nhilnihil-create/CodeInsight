// https://atcoder.jp/contests/abc125/tasks/abc125_a

#include <bits/stdc++.h>
using namespace std;
int solve()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, t, n, ans = 0, count = 0;
  string s;
  vector<int> v(n, 0);
  cin >> a >> b >> t;

  ans = t / a;

  cout << ans * b << endl;
  return 0;
}
signed main()
{
  solve();
}