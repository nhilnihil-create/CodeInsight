#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

// 隣接リストを用いた深さ優先探索（再帰ver.） O(|V|+|E|)
vector<int> G[MAX], color(MAX), score(MAX);
// main関数からこれらを削除すること

int it = 0;
void dfs(int u, vector<int> &c) {
  color[u] = 1; // GRAY
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (color[v] == 0) dfs(v, c);
  }
  color[u] = 2; // BLACK
  score[u] = c.at(it);
  it++;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 無向(有向)グラフの隣接リスト
  int n; // n:頂点数
  cin >> n;
  
  // vector<int> G[n]; // G:頂点数がnのグラフを表す隣接リスト
  
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u); // 有向グラフではこの行をコメントアウト
  }
  
  vector<int> c(n);
  for (int i = 0; i < n; i++) cin >> c.at(i);
  
  sort(c.begin(), c.end());
  
  dfs(0, c);
  
  int totalscore = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < G[i].size(); j++) {
      totalscore += min(score[i], score[G[i][j]]);
    }
  }
  totalscore /= 2;
  
  cout << totalscore << '\n';
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << score[i];
  }
  cout << '\n';
}