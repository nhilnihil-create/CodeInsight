#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <utility>
#include <boost/foreach.hpp>
#include <cmath>

class UnionFind {
  std::vector<int> parent, height;
public:
  UnionFind(const int node_size) : parent(node_size), height(node_size, 0) {
    for (int i = 0; i < node_size; i++) {
      parent[i] = i;
    }
  }
  // O(α(N))
  int Find(const int x) {
    if (parent[x] == x) {
      return x;
    }
    else {
      // 経路圧縮
      return parent[x] = Find(parent[x]);
    }
  }
  // O(α(N))
  void Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) {
      return;
    }
    // ランク
    if (height[x] < height[y]) {
      parent[x] = y;
    }
    else {
      parent[y] = x;
      if (height[x] == height[y]) {
        ++height[x];
      }
    }
  }
};

long long int N, M, ans;
long long int a[50 + 1], b[50 + 1];

int main() {
  std::cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    std::cin >> a[i] >> b[i];
  }

  // i 番目の辺をはぶいて
  for (int i = 1; i <= M; i++) {
    UnionFind uf(N);
    for (int j = 1; j <= M; j++) {
      if (i == j) {
        continue;
      }
      uf.Union(a[j] - 1, b[j] - 1);
    }

    int parent = uf.Find(0);
    for (int j = 1; j < N; j++) {
      if (uf.Find(j) != parent) {
        ans++;
        goto retry;
      }
    }
retry:
    continue;
  }

  std::cout << ans << std::endl;

  return 0;
}