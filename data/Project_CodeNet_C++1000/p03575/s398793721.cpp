#include <bits/stdc++.h>
using namespace std;

class biconnected {
private:
  void dfs(int u, int p, int &tm) {
    bool flag = false;
    ord.at(u) = low.at(u) = tm++, st.push(u);
    for (int v : G.at(u)) {
      if (ord.at(v) < 0) {
        dfs(v, u, tm);
        low.at(u) = min(low.at(u), low.at(v));
      } else if (v != p) {
        low.at(u) = min(low.at(u), ord.at(v));
      } else{
        if (flag) low.at(u) = min(low.at(u), ord.at(v));
        else flag = true;
      }
    }
    if (ord.at(u) == low.at(u)) {
      if (p >= 0) bridge.emplace_back(u, p);
      while(true) {
        const int v = st.top();
        st.pop();
        cmp.at(v) = kind;
        if (v == u) break;
      }
      kind++;
    }
  }
public:
  const int V;
  int kind;
  vector<vector<int>> G, tree;
  vector<pair<int, int>> bridge;
  vector<int> ord, low, cmp;
  stack<int> st;
  biconnected(int node_size) : V(node_size), kind(0), G(V), ord(V, -1), low(V), cmp(V) {}
  void add(const int u, const int v) {
    G.at(u).push_back(v), G.at(v).push_back(u);
  }
  int detect_bridge() {
  int tm = 0;
  for (int i = 0; i < V; i++) {
    if (ord.at(i) < 0) dfs(i, -1, tm);
  }
  for (int i = 0; i < V; i++) cmp.at(i) = kind - 1 - cmp.at(i);
  return kind;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  biconnected B(N);
  while (M--) {
    int a, b;
    cin >> a >> b;
    B.add(--a, --b);
  }
  cout << B.detect_bridge() - 1 << "\n";
}