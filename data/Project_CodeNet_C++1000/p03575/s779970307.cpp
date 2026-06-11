#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

// グラフ上の深さ優先探索
vector<bool> seen;
void dfs(const Graph G, int v, int a, int b) {
  seen[v] = true; // vを訪問済にする
  // vから行ける各頂点 next_v について
  for (auto next_v : G[v]) {
    if (seen[next_v]||(v==a&&next_v==b)||(v==b&&next_v==a)) continue; // next_vが探索済だったらスルー
    dfs(G, next_v, a, b); // 再帰的に探索
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  for (int i=0; i<M; i++) cin >> a[i] >> b[i], a[i]--, b[i]--;
  // グラフへの入力(重みなし)
  Graph G(N);
  for (int i=0; i<M; i++) {
    G[a[i]].push_back(b[i]);
    // 無向グラフの場合は以下を追加
    G[b[i]].push_back(a[i]);
  }
  // i番目の辺を除いた時を考える
  int res = 0;
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      seen.assign(N, false);
      dfs(G, j, a[i], b[i]);
      for (int k=0; k<N; k++) {
        if (!seen[k]) {
          res++;
          break;
        }
      }
    }
  }
  cout << res/N << endl;
  return 0;
}