#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> table(m, vector<int>(n));
  rep(i, m)
  {
    int k;
    cin >> k;
    rep(j, k)
    {
      int s;
      cin >> s;
      table[i][s - 1] = 1;
    }
  }
  vector<int> p(m);
  rep(i, m) cin >> p[i];
  int ans = 0;
  rep(i, 1 << n)
  {
    bool ok = true;
    rep(j, m)
    {
      int on = 0;
      rep(k, n)
      {
        if (table[j][k] == 1 && i & (1 << k))
          on++;
      }
      if (p[j] != on % 2)
        ok = false;
    }
    if (ok)
      ans++;
  }
  cout << ans << endl;
  return 0;
}