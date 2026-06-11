#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
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
  vector<ll> b(n);
  rep(i, n) cin>>a[i];
  rep(i, n) cin>>b[i];
  vector<pair<ll, ll>> c(n);
  ll asum = 0;
  ll bsum = 0;
  ll sum = 0;
  rep(i, n) {
    asum += a[i];
    bsum += b[i];
    sum += max(0LL, a[i] - b[i]);
    c[i] = make_pair(a[i]-b[i], i);
  }
  if (asum < bsum) {
    cout << -1 << endl;
    return 0;
  }
  sort(c.begin(),c.end());
  vector<ll> d = b;
  rep(i, n) {
    ll idx = c[i].second;
    ll t = min(sum, abs(c[i].first));
    sum -= t;
    d[idx] += t;
  }
  ll ans = 0;
  rep(i, n) {
    if (a[i] != d[i]) ans++;
  }
  cout << ans << endl;

  return 0;
}
