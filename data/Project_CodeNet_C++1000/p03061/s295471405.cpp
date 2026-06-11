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
  vector<ll> a(n);
  rep(i, n) cin>>a[i];

  vector<ll> l(n);
  rep(i, n) {
    if (i == 0) l[i] = a[i];
    else l[i] = gcd(l[i-1], a[i]);
  }

  vector<ll> r(n);
  for (int i=n-1; i>=0; i--) {
    if (i == n-1) r[i] = a[i];
    else r[i] = gcd(r[i+1], a[i]);
  }

  ll ans = 0;
  rep(i, n) {
    ll tmp = 0;
    if (i == 0) tmp = r[i+1];
    else if (i == n-1) tmp = l[i-1];
    else tmp = gcd(l[i-1], r[i+1]);
    ans = max(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}
