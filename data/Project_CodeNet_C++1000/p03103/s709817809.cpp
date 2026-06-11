#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
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
  ll n,m; cin>>n>>m;
  vector<pair<ll, ll>> p(n);
  rep(i, n) {
    ll a,b; cin>>a>>b;
    p[i] = make_pair(a,b);
  }
  sort(p.begin(),p.end());
  ll ans = 0;
  ll cnt = 0;
  rep(i, n) {
    rep(j, p[i].second) {
      if (cnt >= m) break;
      ans += p[i].first;
      cnt++;
    }
  }
  cout << ans << endl;

  return 0;
}
