#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 2e5+10;

vector<int> adj[N];

bool vis[N];
int d[N];
void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (!vis[v]) {
      d[v] = d[u]+1;
      dfs(v);
    }
  }
}

char dp[N];
bool solve(int x) {
  if (x < 0) return 1;
  if (!x) return 1;
  if (dp[x] != -1) return dp[x];
  if (!solve(x-1) || !solve(x-2)) return dp[x] = 1;
  return dp[x] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof dp);
  //for (int i = 0; i < 15; i++) cerr << solve(i) << " "; cerr << nl; return 0;
  int n; cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  int u = max_element(d, d + n) - d;
  d[u] = 0;
  memset(vis, 0, sizeof vis);
  dfs(u);
  int diam = *max_element(d, d + n);
  puts(solve(diam) ? "First" : "Second");
  return 0;
}
