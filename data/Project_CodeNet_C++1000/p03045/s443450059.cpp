#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

#ifdef _DEBUG
inline void dump() { cerr << endl; }
template<typename Head> void dump(Head&& head) { cerr << head; dump(); }
template<typename Head, typename... Tail> void dump(Head&& head, Tail&&... tail) { cerr << head << ", "; dump(forward<Tail>(tail)...); }
#define debug(...) do {cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; dump(__VA_ARGS__); } while (false)
#else
#define dump(...)
#define debug(...)
#endif

template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////
const ll inf = 1LL<<60;

struct UnionFind {
  vector<int> data;
  UnionFind(int n) {
    init(n);
  }
  void init(int n=1) {
    data.assign(n, -1);
  }
  int root(int x) {
    if (data[x] < 0) return x;
    return (data[x] = root(data[x]));
  }
  bool issame(int x, int y) {
    return (root(x) == root(y));
  }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }
  int size(int x) {
    return (-data[root(x)]);
  }
};

int main()
{
  ll n,m; cin>>n>>m;
  vector<ll> x(m);
  vector<ll> y(m);
  vector<ll> z(m);
  rep(i, m) {
    cin>>x[i]>>y[i]>>z[i];
    x[i]--; y[i]--;
    z[i] %= 2;
  }
  UnionFind uf(n);
  rep(i, m) {
    uf.merge(x[i], y[i]);
  }
  set<ll> st;
  rep(i, n) {
    st.insert(uf.root(i));
  }
  cout << st.size() << endl;

  return 0;
}
