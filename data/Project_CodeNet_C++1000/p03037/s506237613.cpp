#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> v(n + 1, 0);
  for (int i = 0; i < m; i++)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    v.at(l)++;
    v.at(r + 1)--;
  }
  for (int i = 1; i <= n; i++)
  {
    v.at(i) += v.at(i - 1);
  }
  for (int i = 0; i < n; i++)
  {
    if (v[i] == m)
      ans++;
  }
  cout << ans << endl;
}