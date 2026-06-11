/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t V, E;
  cin >> V >> E;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<vector<int64_t>> connected(V + 1);
  vector<Pair> edges;
  for (int64_t i = 0; i < E; ++i) {
    int64_t a, b;
    cin >> a >> b;
    connected[a].emplace_back(b);
    connected[b].emplace_back(a);
    edges.emplace_back(a, b);
  }
  int64_t result = 0;
  for (const auto &edge : edges) {
    vector<bool> visited(V + 1, false);
    queue<int64_t> q;
    auto Visit = [&](const int64_t vertex) {
      visited[vertex] = true;
      for (const auto &next : connected[vertex]) {
        if ((edge.first == vertex && edge.second == next) || (edge.first == next && edge.second == vertex)) {
          // DO NOTHING
        } else {
          if (!visited[next]) {
            visited[vertex] = true;
            q.emplace(next);
          }
        }
      }
    };
    Visit(1);
    while (!q.empty()) {
      int64_t v = q.front();
      q.pop();
      Visit(v);
    }
    bool is_bridge = false;
    for (int64_t v = 1; v <= V; ++v) {
      if (!visited[v]) {
        is_bridge = true;
      }
    }
    if (is_bridge) {
      ++result;
    }
  }
  cout << result << endl;
  return 0;
}
