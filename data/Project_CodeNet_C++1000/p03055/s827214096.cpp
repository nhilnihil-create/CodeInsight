#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Edge {
  const int from, to;
  Edge(int from, int to) : from(from), to(to) {}
};

vector<vector<Edge>> ReadUndirectedGraph(
    int n, int m, bool is_one_indexed=false) {
  vector<vector<Edge>> graph(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    if (is_one_indexed) {
      v1--;
      v2--;
    }
    graph[v1].push_back(Edge(v1, v2));
    graph[v2].push_back(Edge(v2, v1));
  }
  return graph;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  auto graph = ReadUndirectedGraph(n, n - 1, true);

  function<tuple<int, int>(int, int)> dfs =
      [&](int v, int p) -> tuple<int, int> {
    auto r = make_tuple(v, 0);
    for (const auto& e : graph[v]) {
      if (e.to == p) continue;
      int arg, value;
      tie(arg, value) = dfs(e.to, v);
      value += 1;
      if (get<1>(r) < value) {
        r = make_tuple(arg, value);
      }
    }
    return r;
  };
  int v;
  tie(v, ignore) = dfs(0, -1);
  int d;
  tie(ignore, d) = dfs(v, -1);
  if (d % 3 == 1) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
}