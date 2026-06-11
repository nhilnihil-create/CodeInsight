#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

struct P { int x, y; };
int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<P> R(N), B(N);
  for(auto& r: R) std::cin >> r.x >> r.y;
  for(auto& r: B) std::cin >> r.x >> r.y;
  std::vector<std::vector<int>> G(N+N);
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if(R[i].x < B[j].x && R[i].y < B[j].y) {
        G[i].push_back(j+N);
        G[j+N].push_back(i);
      }
    }
  }
  std::vector<bool> used(N+N, false);
  std::vector<int> match(N+N, -1);
  auto dfs = [&](auto&& f, int v)->bool {
    used[v] = true;
    for(int u: G[v]) {
      int w = match[u];
      if(w < 0 || !used[w] && f(f, w)) {
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
    return false;
  };
  int ans = 0;
  for(int v = 0; v < N+N; ++v) if(match[v] < 0) {
    std::fill(used.begin(), used.end(), false);
    if(dfs(dfs, v)) ++ans;
  }
  fin(ans);
  return 0;
}
