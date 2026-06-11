#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;
vector<int> to[100005];
int64_t dp[100005][2]; // 0: 白で塗るパターン数, 1: 黒で塗るパターン数

int64_t dfs(int v, int from, bool black)
{
  if (dp[v][black] != -1)
  {
    return dp[v][black];
  }
  if (to[v].size() == 1 && from != -1)
  {
    return dp[v][black] = 1;
  }
  int64_t ret = 1;
  if (black)
  {
    for (int u : to[v])
    {
      if (u == from)
        continue;
      (ret *= dfs(u, v, 0)) %= MOD;
    }
  }
  else
  {
    for (int u : to[v])
    {
      if (u == from)
        continue;
      (ret *= ((dfs(u, v, 0) + dfs(u, v, 1)) % MOD)) %= MOD;
    }
  }
  return dp[v][black] = ret;
}

int main()
{
  int N, x, y;
  cin >> N;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> x >> y;
    x--, y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }
  for (int i = 0; i < 100005; i++)
  {
    dp[i][0] = dp[i][1] = -1;
  }
  cout << (dfs(0, -1, 0) + dfs(0, -1, 1)) % MOD << endl;
}
