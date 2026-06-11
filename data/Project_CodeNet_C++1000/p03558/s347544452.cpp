#include <bits/stdc++.h>
using namespace std;
#define int long long

struct edge {
  int to, cost;
};

const int MAX_V = 101010;
const int INF = 1e18;

int K, V;
vector<edge> G[MAX_V];

struct Dijkstra {
  int d[MAX_V];

  void dijkstra(int s) {
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
      P p = que.top();
      que.pop();
      int v = p.second;
      if (d[v] < p.first)
        continue;
      for (int i = 0; i < G[v].size(); i++) {
        edge e = G[v][i];
        if (d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          que.push(P(d[e.to], e.to));
        }
      }
    }
  }
};

signed main() {
  cin >> K;
  V = K;
  for (int i = 0; i < K; i++) {
    G[i].push_back({(i + 1) % K, 1});
  }
  for (int i = 1; i < K; i++) {
    G[i].push_back({(i * 10) % K, 0});
  }

  Dijkstra dij;
  dij.dijkstra(1);

  cout << dij.d[0] + 1LL << endl;
  return 0;
}
