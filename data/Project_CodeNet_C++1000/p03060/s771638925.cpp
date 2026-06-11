#include <bits/stdc++.h>
using namespace std;
int solve()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, ans = 0, count = 0;
  string s;
  cin >> n;
  vector<int> v(n, 0);
  vector<int> c(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++)
  {
    if (v[i] > c[i])
    {
      ans += v[i] - c[i];
    }
  }
  cout << ans << endl;
  return 0;
}
signed main()
{
  solve();
}