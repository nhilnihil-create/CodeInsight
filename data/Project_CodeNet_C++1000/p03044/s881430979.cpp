#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

struct Edge {
  int to;     // 辺の行き先
  int weight; // 辺の重み
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

vector<int> color;
void dfs(const Graph &G, int v) {
  for (auto next_v : G.at(v)) {
    if (color.at(next_v.to) != -1) {
      continue;
    } else {
      color.at(next_v.to) = ((color.at(v) + next_v.weight) % 2);
      dfs(G, next_v.to);
    }
  }
}

int main() {
  // 頂点数と辺数
  int N;
  cin >> N;

  // グラフ
  Graph G(N);
  for (int i = 0; i < N - 1; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    from--;
    to--;
    G.at(from).push_back(Edge(to, weight));
    G.at(to).push_back(Edge(from, weight));
  }

  color.assign(N, -1);
  color.at(0) = 0;
  dfs(G, 0);

  rep(i, N) {
    cout << color.at(i) << endl;
  }
}