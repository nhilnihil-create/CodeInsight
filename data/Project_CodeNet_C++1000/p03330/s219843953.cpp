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
  ll n; cin>>n;
  ll m; cin>>m;
  vector<vector<ll>> d(m, vector<ll>(m));
  rep(i, m) rep(j, m) cin>>d[i][j];
  vector<vector<ll>> c(n, vector<ll>(n));
  rep(i, n) rep(j, n) {
    cin>>c[i][j];
    c[i][j]--;
  }

  vector<map<ll, ll>> mp(3);

  rep(i, n) rep(j, n) {
    mp[(i+j)%3][c[i][j]]++;
  }

  vector<vector<ll>> sum(3, vector<ll>(m));
  rep(k, 3) {
    rep(i, m) {
      rep(j, m) {
        sum[k][i] += d[j][i]*mp[k][j];
      }
    }
  }

  ll ans = inf;
  rep(i, m) rep(j, m) rep(k, m) {
    if (i == j || j == k || k == i) continue;
    ll tmp = sum[0][i] + sum[1][j] + sum[2][k];
    ans = min(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}
