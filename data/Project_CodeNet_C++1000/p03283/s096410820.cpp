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

int main()
{
  ll n,m,q; cin>>n>>m>>q;
  vector<vector<ll>> a(n+2, vector<ll>(n+2));

  rep(i, m) {
    ll l,r; cin>>l>>r;
    a[l][r]++;
  }
  rep(i, n) rep(j, n) {
    a[i+1][j+1] += a[i][j+1] + a[i+1][j] - a[i][j];
  }

  vector<ll> ans;
  while (q--) {
    ll x, y; cin>>x>>y; x--;
    ans.push_back(a[y][y]-a[y][x]-a[x][y]+a[x][x]);
  }

  for (auto v:ans) cout << v << endl;

  return 0;
}
