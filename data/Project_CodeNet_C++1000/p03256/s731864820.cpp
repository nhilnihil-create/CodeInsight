#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename G >
struct StronglyConnectedComponents {
  const G &g;
  UnWeightedGraph gg, rg;
  vector< int > comp, order, used;

  StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for(int i = 0; i < g.size(); i++) {
      for(auto e : g[i]) {
        gg[i].emplace_back((int) e);
        rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return (comp[k]);
  }

  void dfs(int idx) {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  bool build(UnWeightedGraph &t) {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) return true;
        t[x].push_back(y);
      }
    }
    return false;
  }
};

int main() {
  int N, M;
  string S;

  cin >> N >> M;
  cin >> S;
  UnWeightedGraph g(4 * N);
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    for(int j = 0; j < 2; j++) {
      if(S[x] == S[y]) {
        if(S[x] == 'A') g[x].emplace_back(y + N);
        else g[x + N + N].emplace_back(y + N + N + N);
      } else {
        if(S[x] == 'A') g[x + N].emplace_back(y + N + N);
        else g[x + N + N + N].emplace_back(y);
      }
      swap(x, y);
    }
  }
  StronglyConnectedComponents< UnWeightedGraph > scc(g);
  UnWeightedGraph t;
  if(scc.build(t))cout << "Yes\n";
  else cout << "No\n";
}
