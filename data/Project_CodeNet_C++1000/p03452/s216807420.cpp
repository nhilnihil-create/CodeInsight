#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int src, dst;
  long long weight;
  Edge(int f, int t, long long w) {
    src = f;
    dst = t;
    weight = w;
  }
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

bool conflict(Graph &g) {
  int n = g.size();
  vector<long long> dist(n);
  vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (visited[i])
      continue;
    visited[i] = true;
    stack<int> st;
    st.push(i);
    while (!st.empty()) {
      int now = st.top();
      st.pop();
      for (auto e : g[now]) {
        if (visited[e.dst]) {
          if (dist[e.dst] != dist[now] + e.weight) {
            return 0;
          }
        } else {
          dist[e.dst] = dist[now] + e.weight;
          st.push(e.dst);
          visited[e.dst] = true;
        }
      }
    }
  }
  return 1;
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph g(n);
  for (int i = 0; i < m; ++i) {
    int l, r;
    long long d;
    cin >> l >> r >> d;
    g[l - 1].emplace_back(l - 1, r - 1, d);
    g[r - 1].emplace_back(r - 1, l - 1, -d);
  }
  if (conflict(g)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}