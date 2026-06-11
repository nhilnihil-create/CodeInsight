#include<iostream>
#include<vector>

struct E{ int to, cost; };

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<std::vector<E>> G(N);
  for(int i = 0; i < N-1; ++i) {
    int u, v, w; std::cin >> u >> v >> w; --u; --v; w%=2;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  std::vector<int> color(N, 0);
  auto dfs = [&](auto&& f, int v, int p)->void {
    for(E const& e: G[v]) if(e.to != p) {
      color[e.to] = color[v]^e.cost;
      f(f, e.to, v);
    }
  };
  dfs(dfs, 0, -1);
  for(int c: color) std::cout << c << "\n";
  return 0;
}