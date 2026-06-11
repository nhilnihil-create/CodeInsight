#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Edge {
  int to;
  int diff;

  Edge(int to, int diff) : to(to), diff(diff) {}
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<Edge>> edges(N);
  for (int i = 0; i < M; i++) {
    int v, u, diff;
    cin >> v >> u >> diff;
    v--;
    u--;
    edges[v].push_back(Edge(u, diff));
    edges[u].push_back(Edge(v, -diff));
  }

  vector<LL> pos(N, 0);
  vector<int> used(N, 0);

  bool ok = true;
  stack<int> vs;
  for (int i = 0; i < N; i++) {
    if (used[i] == 1) continue;
    vs.push(i);
    while (!vs.empty()) {
      int v = vs.top();
      vs.pop();
      // if(used[v] == 1) continue;
      used[v] = 1;
      for (auto e : edges[v]) {
        int u = e.to;
        if (used[u] == 1) {
          if (pos[u] - pos[v] != e.diff) ok = false;
        } else {
          vs.push(u);
          pos[u] = pos[v] + e.diff;
          used[u] = 1;
        }
      }
    }
  }
  for (int v = 0; v < N; v++)
    for (auto e : edges[v]) {
      int u = e.to;
      if (pos[u] - pos[v] != e.diff) ok = false;
    }

  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}