#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

map<int, int> Compress(const vector<int>& raw_xs) {
  set<int> raw_x_set(raw_xs.begin(), raw_xs.end());
  vector<int> to_raw(raw_x_set.begin(), raw_x_set.end());
  map<int, int> to_index;
  for (int i = 0; i < to_raw.size(); i++) {
    to_index[to_raw[i]] = i;
  }
  return to_index;
}

struct Edge {
  const int from, to;
  Edge(int from, int to) : from(from), to(to) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) cin >> xs[i];
  map<int, int> count;
  for (int i = 0; i < n; i++) {
    count[xs[i]]++;
  }

  auto to_index = Compress(xs);
  int index_size = to_index.size();

  vector<int> i_to_count(index_size);
  for (int x : xs) {
    i_to_count[to_index[x]]++;
  }

  vector<vector<Edge>> graph(index_size);
  vector<int> self_loop_vector(index_size);
  for (const auto& kv : to_index) {
    int x1 = kv.first;
    // cout << "x1: " << x1 << endl;
    int y = 1;
    while (y <= x1) y *= 2;
    int x2 = y - x1;
    // cout << "x2: " << x2 << endl;
    if (x1 == x2) {
      // cout << "self_loop_vector: " << to_index[x1] << endl;
      self_loop_vector[to_index[x1]] = true;
    } else if (to_index.find(x2) != to_index.end()) {
      int i1 = to_index[x1];
      int i2 = to_index[x2];
      // cout << "i1: " << i1 << " i2: " << i2 << endl;
      graph[i1].emplace_back(i1, i2);
      graph[i2].emplace_back(i2, i1);
    }
  }

  vector<int> visited(index_size);
  int ans = 0;
  function<void(int,int)> dfs = [&](int v, int p) {
    if (visited[v]) return;
    // cout << "v: " << v << endl;

    for (const auto& e : graph[v]) {
      if (e.to == p) continue;
      dfs(e.to, v);
    }
    if (self_loop_vector[v]) {
      int c = i_to_count[v] / 2;
      ans += c;
      i_to_count[v] -= 2 * c;
    }
    if (p >= 0) {
      if (i_to_count[v] > 0 && i_to_count[p] > 0) {
        // cout << "v: " << v << " p: " << p << endl;
        int c = min(i_to_count[v], i_to_count[p]);
        ans += c;
        i_to_count[v] -= c;
        i_to_count[p] -= c;
      }
    }
    visited[v] = true;
  };
  for (int i = 0; i < index_size; i++) dfs(i, -1);
  cout << ans << endl;
}
