#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
vector<int> G[MAX]; // G:頂点数がnのグラフを表す隣接リスト
vector<int> color(MAX);
list<int> topo;

void dfs(int v) {
  color[v] = 1;
  for (int i = 0; i < G[v].size(); i++) {
    if (color[G[v][i]] == 0) dfs(G[v][i]);
  }
  color[v] = 2;
  topo.emplace_front(v);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 無向(有向)グラフの隣接リスト
  int n, m; // n:頂点数 m:追加した辺の数
  cin >> n >> m;
  
  vector<bool> rootcheck(n, true);
  for (int i = 0; i < n - 1 + m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].emplace_back(v);
    // G[v].emplace_back(u); // 有向グラフではこの行をコメントアウト
    rootcheck.at(v) = false;
  }
  
  int begin;
  for (int i = 0; i < n; i++) {
    if (rootcheck.at(i)) begin = i;
  }
  
  dfs(begin);
  
  vector<int> par(n);
  
  for (auto it = topo.begin(); it != topo.end(); it++) {
    for (int i = 0; i < G[*it].size(); i++) {
      par[G[*it][i]] = *it;
    }
  }
  
  par[*topo.begin()] = -1;
  
  for (int i = 0; i < n; i++) cout << par[i] + 1 << '\n';
}