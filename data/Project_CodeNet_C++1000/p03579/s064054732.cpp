#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>

// union find with count
struct union_find {
  std::vector<int> data, rank;

  explicit union_find(int n): data(n, -1), rank(n,0) {}

  int find(int x) {
    if(data[x] < 0) return x;
    return data[x] = find(data[x]);
  }

  void unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    if(rank[x] > rank[y]) std::swap(x, y);
    data[y] += data[x];
    data[x] = y;
    if(rank[x] == rank[y]) ++rank[y];
  }

  int count(int x){ return -data[find(x)]; }
};

int main() {
  int N, M; std::cin >> N >> M;
  std::vector<std::vector<int>> G(N);
  union_find uf(N+N);
  for(int i = 0; i < M; ++i) {
    int a, b; std::cin >> a >> b; --a; --b;
    uf.unite(a, b+N);
    uf.unite(a+N, b);
  }
  std::map<int,int> m;
  for(int i = 0; i < N; ++i) ++m[uf.find(i)];
  int64_t p = m[uf.find(0)];
  int64_t ans = (p==N? (int64_t)N*(N-1)/2: p*(N-p)) - M;
  std::cout << ans << std::endl;
  return 0;
}
