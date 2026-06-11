#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAX = 1e5;

// 2部グラフ判定
vector<int> d(MAX, -1);
bool bfs(const vector<vector<int>> &G, int s) {
  queue<int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      if (d[G[u][i]] == -1) {
        d[G[u][i]] = (d[u] + 1) % 2;
        q.push(G[u][i]);
      }
      else if (d[G[u][i]] == d[u]) return false;
    }
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 無向(有向)グラフの隣接リスト
  ll n, m; // n:頂点数 m:辺数
  cin >> n >> m;
  
  vector<vector<int>> G(n); // G:頂点数nのグラフの隣接リスト
  
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u); // 有向グラフではコメントアウト
  }
  
  if (!bfs(G, 0)) {
    cout << n * (n - 1) / 2 - m << '\n';
    return 0;
  }
  
  ll one = 0;
  for (int i = 0; i < n; i++) {
    if (d[i] == 1) one++;
  }
  
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (d[i] == 0) {
      ans += one - G[i].size();
    }
  }
  
  cout << ans << '\n';
  return 0;
}