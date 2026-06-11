#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

struct Edge {
  int to;
  int cost;

  Edge(int a, int b) {
    to = a;
    cost = b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<Edge>> edges(n);
  rep(i, 0, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges[u].emplace_back(v, w);
    edges[v].emplace_back(u, w);
  }

  vector<ll> G(n, -1);
  G[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto edge : edges[node]) {
      if (G[edge.to] != -1)
        continue;
      G[edge.to] = G[node] + edge.cost;
      q.push(edge.to);
    }
  }

  rep(i, 0, n) {
    if (G[i] % 2 == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
}
