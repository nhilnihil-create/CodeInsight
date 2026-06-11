#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(m, vector<int>(n, 0));
  vector<int> p(m);
  for (int i = 0; i < m; i++)
  {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
      int connect;
      cin >> connect;
      connect--;
      s[i][connect]++;
    }
  }
  for (int i = 0; i < m; i++)
  {
    cin >> p[i];
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++)
  {
    vector<int> sw(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (bit & (1 << i))
      {
        sw[i]++;
      }
    }
    bool ok = true;
    for (int i = 0; i < m; i++)
    {
      int cnt = 0;
      for (int j = 0; j < n; j++)
      {
        if (s[i][j] + sw[j] == 2)
        {
          cnt++;
        }
      }
      if (cnt % 2 != p[i])
      {
        ok = false;
      }
    }
    if (ok)
    {
      ans++;
    }
  }
  cout << ans << endl;
}
