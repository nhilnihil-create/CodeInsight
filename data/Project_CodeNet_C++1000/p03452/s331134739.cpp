#include <iostream>
#include <vector>

const int INF = 1 << 30;

using Edge = std::pair<int, int>;
using Graph = std::vector<std::vector<Edge>>;
Graph G;

std::vector<bool> visited;
std::vector<int> X;

void dfs(const int v, bool &res) {
  visited[v] = true;

  for (auto e : G[v]) {
    int nv = e.first;
    int d = e.second;
    if (visited[nv]) {
      if (X[nv] != X[v] + d)
        res = false;
      continue;
    }

    X[nv] = X[v] + d;
    dfs(nv, res);
  }
}

int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> L(M), R(M), D(M);
  for (int i = 0; i < M; ++i) {
    std::cin >> L[i] >> R[i] >> D[i];
    --L[i], --R[i];
  }

  G.resize(N);
  for (int i = 0; i < M; ++i) {
    G[L[i]].push_back(std::make_pair(R[i], D[i]));
    G[R[i]].push_back(std::make_pair(L[i], -D[i]));
  }

  visited.assign(N, false);
  X.assign(N, 0);

  bool res = true;
  for (int v = 0; v < N; ++v) {
    if (visited[v])
      continue;
    dfs(v, res);
  }

  if (res)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}
