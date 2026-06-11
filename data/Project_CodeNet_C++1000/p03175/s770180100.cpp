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
vector<vector<int>> dp;
void dfs(int u, int pu = -1) {
  dp[u][0] = dp[u][1] = 1;
  for (int v : g[u]) {
    if (v == pu)
      continue;
    dfs(v, u);
    dp[u][1] = (dp[u][1] * dp[v][0]) % mod;
    dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % mod;
  }
}
void init() {
  int n;
  cin >> n;
  g.resize(n);
  dp = vector<vector<int>>(n, vector<int>(2));
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(0);
  cout << (dp[0][0] + dp[0][1])%mod << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
