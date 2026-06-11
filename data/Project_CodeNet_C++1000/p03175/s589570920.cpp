#include<bits/stdc++.h>
#define F first
#define S second
#define REP(i, a, b, c) for(int i = a; i <= b; i+=c)
#define pb push_back
#define int long long int
#define MOD 1000000007
using namespace std;

vector<int> tree[100001];
int dp[100001][2];

int solve(int u, bool constr, int pr)
{
  if (dp[u][constr] != -1)
    return dp[u][constr];
  int ans = 0;
  int w1 = 1;
  for (int child : tree[u]) {
    if (child != pr)
    {
      w1 = (w1 * solve(child, 0, u)) % MOD;
    }
  }
  ans = (ans + w1) % MOD;
  if (!constr)
  {
    int w2 = 1;
    for (int child : tree[u]) {
      if (child != pr)
      {
        w2 = (w2 * solve(child, 1, u)) % MOD;
      }
    }
    ans = (ans + w2) % MOD;
  }
  return dp[u][constr] = ans;
}

int32_t main()
{
  ios :: sync_with_stdio(false); cin.tie(0);
  int t = 1;
  //cin >> t;
  for (int i9 = 1; i9 <= t; i9++)
  {
    int n;
    cin >> n;
    n--;
    memset(dp, -1, sizeof(dp));
    while (n--)
    {
      int x, y;
      cin >> x >> y;
      tree[x].pb(y);
      tree[y].pb(x);
    }
    cout << solve(1, 0, -1);
  }
}

