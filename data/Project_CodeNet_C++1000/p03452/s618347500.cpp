#include <bits/stdc++.h>
using namespace std;

#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)
#define rep(i, n) repi(i, 0, n)
#define all(x) (x).begin(), (x).end()

template< typename T >
struct WeightedUnionFind {
  vector< int > data;
  vector< T > ws;

  WeightedUnionFind() {}

  WeightedUnionFind(int sz) : data(sz, -1), ws(sz) {}

  int find(int k) {
    if(data[k] < 0) return k;
    auto par = find(data[k]);
    ws[k] += ws[data[k]];
    return data[k] = par;
  }

  T weight(int t) {
    find(t);
    return ws[t];
  }

  bool unite(int x, int y, T w) {
    w += weight(x);
    w -= weight(y);
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) {
      swap(x, y);
      w *= -1;
    }
    data[x] += data[y];
    data[y] = x;
    ws[y] = w;
    return true;
  }

  T diff(int x, int y) {
    return weight(y) - weight(x);
  }
};

inline void Main() {
  // code
  int n,m,l,r,d;
  cin>>n>>m;
  WeightedUnionFind<int> uf(n);
  rep(i,m) {
    cin>>l>>r>>d;
    l--;r--;

    if(uf.find(l) == uf.find(r)) {
      if(uf.diff(l,r) != d) {
        cout << "No" << endl;
        return;
      }
    }
    else uf.unite(l,r,d);
  }
  cout << "Yes" << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(20);
  Main();
  return 0;
}
