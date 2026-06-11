#include <bits/stdc++.h>
using namespace std;

class tsort {
public:
  int V;
  vector<vector<int>> G;
  vector<int> deg, res;
  tsort(int node_size) : V(node_size), G(V), deg(V, 0) {}
  void add(int from, int to) {
    G.at(from).push_back(to);
    deg.at(to)++;
  }
  bool solve() {
    queue<int> que;
    for(int i = 0; i < V; i++) {
      if(deg.at(i) == 0) {
        que.push(i);
      }
    }
    while(!que.empty()) {
      int p = que.front();
      que.pop();
      res.push_back(p);
      for(int v : G.at(p)) {
        if(--deg.at(v) == 0) {
          que.push(v);
        }
      }
    }
    return (*max_element(deg.begin(),deg.end()) == 0);
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  tsort T(N);
  for (int i = 0; i < N - 1 + M; i++) {
    int a, b;
    cin >> a >> b;
    G.at(--b).push_back(--a);
    T.add(a, b);
  }
  T.solve();
  vector<int> V(N);
  int rank = 0;
  for (auto r : T.res) V.at(r) = rank++;
  for (int i = 0; i < N; i++) {
    if (G.at(i).size() == 0) {
      cout << 0 << "\n";
      continue;
    }
    int ans, mx = -1;
    for (auto g : G.at(i)) if (V.at(g) > mx) mx = V.at(g), ans = g;
    cout << ans + 1 << "\n";
  }
}