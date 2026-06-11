#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

// 二部グラフ判定
vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
  color[v] = cur;

  for (auto next_v : G[v]) {
    // 隣接頂点の色がすでに確定していた場合
    if (color[next_v] != -1) {
      if (color[next_v] == cur) return false; // 同色が隣接したらNG
      continue;
    }

    // 隣接頂点の色を変えて、再帰的に探索
    // (一度でも false が帰ってきたら false で終了)
    if (!dfs(G, next_v, 1 - cur)) return false;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // 頂点数と辺数
  ll N, M; cin >> N >> M;

  // グラフ入力受取
  Graph G(N);
  for (ll i = 0; i < M; i++) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  // 探索
  color.assign(N, -1);
  bool is_bipartite = dfs(G, 0);

  if (is_bipartite) {
    ll B = 0, W = 0;
    for (ll i = 0; i < N; i++) {
      color[i] == 0 ? B++ : W++;
    }
    cout << B * W - M << endl;
  } else {
    cout << N * (N - 1) / 2 - M << endl;
  }
}
