#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int n;
vector<vector<int>> g;
vector<bool> chk;
int ans;

void dfs(int pre, int crt)
{
  if (chk[crt])
    return;
  if (pre == -1)
    ans++;
  chk[crt] = true;
  for (int nxt : g[crt])
    if (nxt != pre)
      dfs(crt, nxt);
}

int main()
{
  int m;
  cin >> n >> m;
  g.resize(n);
  rep(i, m)
  {
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  chk.resize(n);
  fill(chk.begin(), chk.end(), false);
  ans = 0;
  rep(i, n)
    dfs(-1, i);
  cout << ans << endl;
}