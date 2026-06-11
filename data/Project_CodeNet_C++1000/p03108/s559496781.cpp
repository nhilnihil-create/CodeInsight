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
public:
  std::vector<int> parent, height, count;
  UnionFind(const int node_size) : parent(node_size), height(node_size, 0), count(node_size, 1) {
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
      count[y] += count[x];
    }
    else {
      parent[y] = x;
      count[x] += count[y];
      if (height[x] == height[y]) {
        ++height[x];
      }
    }
  }
};

long long int N, M, first;
long long int A[100000 + 1], B[100000 + 1];
std::vector<long long int> ans;

void func1() {
  long long int tmp = 1;
  tmp = N * (N - 1);
  tmp /= 2;
  first = tmp;
  ans.push_back(tmp);
}

void func2() {
  UnionFind uf(N);
  for (long long int i = M; i >= 2; i--) {
    if (uf.Find(A[i] - 1) != uf.Find(B[i] - 1)) {
      first -= uf.count[uf.Find(A[i] - 1)] * uf.count[uf.Find(B[i] - 1)];
    }
    ans.push_back(first);
    uf.Union(A[i] - 1, B[i] - 1);
  }
}

int main() {
  std::cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    std::cin >> A[i] >> B[i];
  }

  func1();
  func2();

  for (long long int i = ans.size() - 1; i >= 0; i--) {
    std::cout << ans[i] << std::endl;
  }

  return 0;
}