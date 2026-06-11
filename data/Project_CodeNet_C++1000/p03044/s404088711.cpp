#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

vector<vector<int>> to;
vector<vector<int>> cost;
vector<int> ans;

void dfs(int v, int p = -1) {
  rep(i, to[v].size()) {
    int u = to[v][i];
    int w = cost[v][i];
    // cout << u << endl;
    if (u == p) continue;
    ans[u] = (ans[v] + w) % 2;
    dfs(u, v);
  }
}
int main() {
  int n;
  cin >> n;
  to.resize(n);
  cost.resize(n);
  ans.resize(n);
  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    to[u].push_back(v);
    to[v].push_back(u);
    cost[u].push_back(w);
    cost[v].push_back(w);
  }
  dfs(0);
  rep(i, n) cout << ans[i] << endl;
  return 0;
}