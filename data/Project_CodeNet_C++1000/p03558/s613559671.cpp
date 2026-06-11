#include <bits/stdc++.h>
using namespace std;

struct Dijkstra {
  Dijkstra(int V) : V(V), G(V) {}
  struct edge {
    edge(int to, long long cost) : to(to), cost(cost) {}
    int to;
    long long cost;
  };

  using P = pair<long long, int>;
  const long long inf = 1001001001001001001ll;

  int V;
  vector<vector<edge>> G;
  vector<long long> d;

  void init(int n) {
    V = n;
    G.resize(n);
  }

  void debug() {
    cerr << "edges : " << endl;
    for (int i = 0; i < V; ++i)
      for (auto e : G[i]) cerr << i << " -> " << e.to << " : " << e.cost << endl;
    cerr << endl << "dist : " << endl;
    for (int i = 0; i < V; ++i) cerr << i << " : " << d[i] << endl;
  }

  void add_edge(int u, int v, long long c) {
    G[u].push_back(edge(v, c));
  }

  void build(int s) {
    d.assign(V, inf);
    priority_queue<P, vector<P>, greater<P>> q;

    d[s] = 0;
    q.push(P(0ll, s));

    while (!q.empty()) {
      P p = q.top();
      q.pop();
      int v = p.second;
      if (d[v] < p.first) continue;
      for (auto &e : G[v])
        if (d[e.to] > p.first + e.cost) {
          d[e.to] = p.first + e.cost;
          q.push(P(d[e.to], e.to));
        }
    }
  }

  long long operator[](int v) {
    return d[v];
  }
};

int main() {
  int K;
  cin >> K;

  Dijkstra G(K);
  for (int i = 0; i < K; ++i) {
    if (i % 10 != 9) {
      G.add_edge(i, (i + 1) % K, 1);
    }
    G.add_edge(i, 10 * i % K, 0);
  }

  G.build(1);

  cout << G[0] + 1 << endl;
}
