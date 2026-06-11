#include <cstdio>
#include <vector>

#define int long long
#define dotimes(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int rint() {
  int n;
  scanf("%lld", &n);
  return n;
}

void wint(int n) {
  printf("%lld\n", n);
}

struct union_find {
  vector<int> p, w;
  union_find(int n): p(n), w(n) {
    dotimes(x, n) {
      p[x] = x;
      w[x] = 1;
    }
  }
  int abs(int x) {
    return w[find(x)];
  }
  int find(int x) {
    while (x != p[x]) {
      int y = p[x];
      p[x] = p[y];
      x = y;
    }
    return x;
  }
  bool eqv(int x, int y) {
    int a = find(x), b = find(y);
    return a == b;
  }
  bool unite(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b)
      return true;
    if (!(a < b))
      swap(a, b);
    p[b] = a;
    w[a] += w[b];
    return false;
  }
};

signed main() {
  int N = rint();
  int M = rint();
  pair<int, int> edges[M];
  dotimes(i, M) {
    edges[i].first = rint() - 1;
    edges[i].second = rint() - 1;
  }
  union_find uf(N);
  int r[M+1];
  r[M] = N * (N - 1) / 2;
  for (int i = M - 1; i >= 0; i--) {
    int x = uf.find(edges[i].first), y = uf.find(edges[i].second);
    if (x == y)
      r[i] = r[i+1];
    else {
      r[i] = r[i+1] - uf.abs(x) * uf.abs(y);
      uf.unite(x, y);
    }
  }
  dotimes(i, M)
    wint(r[i+1]);
  return 0;
}
