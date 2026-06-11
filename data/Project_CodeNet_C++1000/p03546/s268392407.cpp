#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

// <最短距離, 頂点の番号>
using P = pair<int, int>;

struct Edge {
  int to;     // 辺の行き先
  int weight; // 辺の重み
  Edge(int t, int w): to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int dijkstra (Graph G, int s) {
  vector<int> d(G.size());
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d.begin(), d.end(), INT_MAX);
  d[s] = 0;
  que.push(P(0, s));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v]<p.first) continue;
    for (int i=0; i<G[v].size(); i++) {
      Edge e = G[v][i];
      if (d[e.to] > d[v] + e.weight) {
        d[e.to] = d[v] + e.weight;
        que.push(P(d[e.to], e.to));
      }
    }
  }
  if (d[1]!=INT_MAX) return d[1];
}

int main() {
  int H, W;
  cin >> H >> W;
  // グラフへの入力(重み付き有向グラフ)
  Graph G(10);
  for (int i=0; i<10; i++) {
    for (int j=0; j<10; j++) {
      int from = i, to = j, weight;
      cin >> weight;
      G[from].push_back(Edge(to, weight));
    }
  }
  vector<vector<int>> A(H, vector<int>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) cin >> A[i][j];
  }
  int res = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (A[i][j]!=-1&&A[i][j]!=1) {
        res += dijkstra(G, A[i][j]);
      }
    }
  }
  cout << res << endl;
  return 0;
}