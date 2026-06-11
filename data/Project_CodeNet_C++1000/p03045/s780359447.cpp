#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

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
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, M; std::cin >> N >> M;
  union_find uf(N);
  for(int i = 0; i < M; ++i) {
    int X, Y, Z; std::cin >> X >> Y >> Z; --X; --Y; //no need to check consistency
    uf.unite(X, Y);
  }
  std::set<int> s;
  for(int i = 0; i < N; ++i) s.insert(uf.find(i));
  fin(s.size());
  return 0;
}
