#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

template <class Weight>
constexpr Weight inf=(Weight(1)<<(8*sizeof (Weight)-3));

template <class Weight>
class WeightedUnionFind {
  std::vector<intmax_t> tree;
  std::vector<Weight> cost;

public:
  WeightedUnionFind(size_t n): tree(n, -1), cost(n) {}

  size_t find(size_t v) {
    fprintf(stderr, "? %zu [%jd]\n", v, tree[v]);
    if (tree[v] < 0)
      return v;

    size_t r=find(tree[v]);
    cost[v] += cost[tree[v]];
    return (tree[v] = r);
  }

  bool unite(size_t u, size_t v, Weight w) {
    size_t ru=find(u), rv=find(v);
    if (ru == rv)
      return false;  // FIXME assuming no multi-edges

    if (-tree[ru] < -tree[rv]) {
      tree[rv] += tree[ru];
      tree[ru] = rv;
      cost[ru] = w-(cost[u]-cost[v]);
    } else {
      tree[ru] += tree[rv];
      tree[rv] = ru;
      cost[rv] = -w+(cost[u]-cost[v]);
    }
    fprintf(stderr, "%zu <-> %zu\n", u, v);
    return true;
  }

  bool connected(size_t u, size_t v) {
    return (find(u) == find(v));
  }

  Weight diff(size_t u, size_t v) {
    return connected(u, v)? (cost[u]-cost[v]):inf<Weight>;
  }

  size_t size(size_t v) {
    return -tree[find(v)];
  }
};

int main() {
  size_t N;
  int M;
  scanf("%zu %d", &N, &M);

  WeightedUnionFind<intmax_t> uf(N);

  for (int i=0; i<M; ++i) {
    size_t L, R;
    intmax_t D;
    scanf("%zu %zu %jd", &L, &R, &D);

    --L;
    --R;
    if (!uf.connected(L, R)) {
      uf.unite(L, R, D);
    } else if (uf.diff(L, R) != D) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
}
