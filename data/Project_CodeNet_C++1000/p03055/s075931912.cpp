#include <bits/stdc++.h>
using namespace std;

class TreeDiameter {
public:
  int V;
  vector<vector<int>> G;
  vector<int> diameter;
  TreeDiameter(int node_size) : V(node_size),  G(V) {}
  void add(int u, int v) {
    G.at(u).push_back(v), G.at(v).push_back(u);
  }
  void dfs(int u, int p, int d, int &far, int &mx) {
    if (mx < d) {
      far = u;
      mx = d;
    }
    for (int v : G.at(u)) {
      if (v != p) {
        dfs(v, u, d + 1, far, mx);
      }
    }
  }
  bool redfs(int u, int p, const int t) {
    if (u == t) {
      return true;
    }
    for (int v : G.at(u)) {
      if (v != p) {
      diameter.push_back(v);
      if (redfs(v, u, t)) {
        return true;
      } else {
        diameter.pop_back();
      }
      }
    }
    return false;
  }
  void solve() {
    int s, t, mx;
    mx = -1;
    dfs(0, -1, 0, s, mx);
    mx = -1;
    dfs(s, -1, 0, t, mx);
    diameter.push_back(s);
    redfs(s, -1, t);
  }
};

int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  TreeDiameter TD(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    TD.add(--a, --b);
  }
  TD.solve();
  int D = TD.diameter.size() - 1;
  cout << ((D % 3 == 1) ? "Second" : "First") << "\n";
}