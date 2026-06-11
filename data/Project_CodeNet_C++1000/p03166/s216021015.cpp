#include <iostream>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

constexpr size_t MAXN = 1e5;
constexpr size_t MAXM = 1e5;
constexpr int MOD = 1e9 + 7;

std::vector<std::vector<int>> graph;
std::vector<int> dp;
std::vector<bool> traversed;

void traverse(int to) {
  for (int from : graph[to]) {
    if (!traversed[from]) {
      traverse(from);
      traversed[from] = true;
    }
    dp[to] = std::max(dp[to], dp[from] + 1);
  }
}

void solve() {
  int N, M;
  std::cin >> N >> M;
  graph.resize(N + 1);
  dp.resize(N + 1);
  traversed.resize(N + 1);
  for (int i = 0; i < M; ++i) {
    int from, to;
    std::cin >> from >> to;
    graph[to].push_back(from);
  }

  for (int to = 1; to <= N; to++) {
    if (!graph[to].empty()) {
      traverse(to);
    }
  }

  int mx = dp[0];
  for (int to : dp) {
    mx = std::max(to, mx);
  }

  std::cout << mx << "\n";
}

void warp() {
std::ios_base::sync_with_stdio(false);
std::cin.tie(0);
std::cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}

int main() {
warp();
solve();
return 0;
}
