#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

long long N, M;
std::vector<std::vector<int>> graph;
std::vector<int> color_vec;

// paint color
// 一つでも矛盾があれば, falseを伝搬して欲しい
// falseを伝搬するやつ
// 根本的なfalseのベースケース
// If bipartite graph, return ture.
int black = 0;

bool dfs(int target_node, int color) {
  color_vec[target_node] = color;
  for (auto e: graph[target_node]) {
    if (color_vec[e] == color) {
      return false;
    }
    if (color_vec[e] == 0 && !dfs(e, -color)) {
      return false;
    }
  }
  return true;
}

int main() {
  std::cin >> N >> M;
  graph.assign(N, std::vector<int>());
  color_vec.assign(N, 0);
  for (int i = 0; i < M; ++i) {
    int A, B;
    std::cin >> A >> B;
    --A;
    --B;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  if (dfs(0, 1)) {
    black = std::count(color_vec.begin(), color_vec.end(), 1);
    std::cout << black*(N-black) - M << std::endl;
  } else {
    std::cout << N*(N-1)/2 - M << std::endl;
  }
}
