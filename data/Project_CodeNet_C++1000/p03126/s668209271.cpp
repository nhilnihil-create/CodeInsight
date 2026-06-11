#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
      int buf;
      cin >> buf;
      a[i].push_back(buf);
    }
  }

  vector<int> tmp(m, 0);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < a[i].size(); j++)
    {
      tmp[a[i][j] - 1]++;
    }
  }

  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    if (tmp[i] == n)
    {
      ans++;
    }
  }
  cout << ans << endl;
}
