#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, ans = 0;
  cin >> n;
  vector<vector<int>> v(2, vector<int>(n));
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> v.at(i).at(j);
    }
  }

  int i, j, k;
  for (i = 0; i < n; i++)
  {
    int buf = 0;
    for (j = 0; j <= i; j++)
    {
      buf += v.at(0).at(j);
    }
    for (k = j - 1; k < n; k++)
    {
      buf += v.at(1).at(k);
    }
    ans = max(ans, buf);
  }
  cout << ans << endl;
}
