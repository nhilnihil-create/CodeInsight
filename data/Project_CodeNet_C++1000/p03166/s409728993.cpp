// https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, int> ipair;
#define int long long
#define pb push_back
#define ff first
#define INF INT_MAX
#define ss second
#define fr(i, j, a) for (int i = j; i < a; i++)
#define cnt_ones(x) __builtin_popcount(x)
#define all(x) x.begin(), x.end()
#define sz size()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<ipair>
#define mp make_pair
#define mod 1000000007
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
vector<vector<int>> g;
vector<int> dp;
int n, m;
int dfs(int u) {
  if (dp[u])
    return dp[u];
  for (int v : g[u]) {
    dp[v] = max(dp[v], dfs(v));
    dp[u] = max(dp[u], 1 + dp[v]);
  }
  if (!dp[u])
    dp[u] = 1;
  return 1;
}
void init() {
  cin >> n >> m;
  dp = vector<int>(n, 0);
  g.resize(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = max(dp[i], dfs(i));
    mx = max(mx, dp[i]);
  }
  cout << mx - 1 << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
