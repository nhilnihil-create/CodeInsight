#include <bits/stdc++.h>
using namespace std;

static const int MAX = 200005;
static const int INF = 1e9;

// 隣接リストを用いた幅優先探索 O(|V|+|E|)
vector<int> G[MAX], d(MAX, INF); // 始点sから頂点iまでの最短距離をd[i]に記録
// main関数からこれらを削除すること

void bfs(int s) {
  queue<int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v < G[u].size(); v++) {
      if (d[G[u][v]] == INF) {
        d[G[u][v]] = d[u] + 1;
        q.push(G[u][v]);
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 無向(有向)グラフの隣接リスト
  int n; // n:頂点数
  cin >> n;
  
  //vector<int> G[n]; // G:頂点数がnのグラフを表す隣接リスト
  
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--;
    v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u); // 有向グラフではこの行をコメントアウト
  }
  
  bfs(0);
  
  int now = 0, maxd = 0;
  for (int i = 0; i < n; i++) {
    if (d[i] > maxd) {
      now = i;
      maxd = d[i];
    }
  }
  
  fill(d.begin(), d.end(), INF);
  bfs(now);
  
  int dia = 0;
  for (int i = 0; i < n; i++) {
    dia = max(dia, d[i]);
  }
  
  if (dia % 3 == 1) cout << "Second\n";
  else cout << "First\n";
}