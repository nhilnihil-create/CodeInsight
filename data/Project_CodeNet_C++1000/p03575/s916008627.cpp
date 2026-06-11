#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

using Graph = vector<vector<int>>;

vector<bool> seen;
int dfs(const Graph &g, int v, int& count, int from, int& ans, vector<int>& low, vector<int>& pre) {
  seen[v] = true;
  pre[v] = count++;
  low[v] = pre[v];

  for (auto next_v: g[v]) {
    if (seen[next_v] == false) {
      low[v] = min(low[v], dfs(g, next_v, count, v, ans, low, pre));
      if (low[next_v] == pre[next_v]) {
        ans++;
      }
    } else {
      if (from == next_v) {
        continue;
      }
      low[v] = min(low[v], low[next_v]);
    }
  }

  return low[v];
}

int main(void) {
  int n, m;
  cin >> n >> m;

  Graph g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> low(n, -1);
  vector<int> pre(n, -1);
  int count = 0;
  int ans = 0;
  seen.assign(n, false);
  dfs(g, 0, count, -1,  ans, low, pre);

  cout << ans << endl;
  
  return 0;
}