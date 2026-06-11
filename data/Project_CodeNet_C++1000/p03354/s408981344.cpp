#include <bits/stdint-uintn.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <chrono>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

template<typename T> using maximum_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;
template<typename T> using minimum_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
std::istream& operator>>(std::istream &is, std::vector<T> &v)
{
  for (typename std::vector<T>::size_type i = 0; i < v.size(); ++i) {
    is >> v[i];
  }
  return is;
}

template<typename ID_TYPE = uint64_t>
class UnionFindTreeBase
{
private:
  std::vector<ID_TYPE> root, rank;

public:
  UnionFindTreeBase(ID_TYPE N)
  {
    root = std::vector<ID_TYPE>(N);
    for (ID_TYPE n = 0; n < N; ++n) { root[n] = n; }
    rank = std::vector<ID_TYPE>(N, 0);
  }

  ID_TYPE find(ID_TYPE x)
  {
    if (root[x] == x) { return x; }

    root[x] = find(root[x]);

    return root[x];
  }

  void unite(ID_TYPE x, ID_TYPE y)
  {
    ID_TYPE x_root = find(x), y_root = find(y);

    if (rank[x_root] > rank[y_root]) {
      root[y_root] = x_root;
    } else if (rank[x_root] < rank[y_root]) {
      root[x_root] = y_root;
    } else if (x_root != y_root) {
      root[y_root] = x_root;
      ++rank[x_root]; 
    }
  }

  bool is_same(ID_TYPE x, ID_TYPE y)
  {
    return find(x) == find(y);
  }

  ID_TYPE operator[](ID_TYPE x) {
    return find(x);
  }
};

typedef UnionFindTreeBase<uint64_t> UnionFindTree;

using namespace std;

int main()
{
  uint64_t N, M;
  cin >> N >> M;

  vector<uint64_t> p(N);
  cin >> p;
  N_TIMES(n, N) { --p[n]; }

	UnionFindTree uf_tree(N);
  N_TIMES(m, M) {
    uint64_t x, y;
    cin >> x >> y;
    --x; --y;

    uf_tree.unite(x, y);
  }

  uint64_t counter = 0;
  N_TIMES(n, N) { 
    if (uf_tree[n] == uf_tree[p[n]]) {
      ++counter;
    }
  }
  cout << counter << endl;

  return 0;
}