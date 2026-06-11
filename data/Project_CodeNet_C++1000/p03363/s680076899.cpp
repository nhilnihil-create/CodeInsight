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
  rep(i, n) cin>>a[i];

  vector<ll> b(n+1);
  rep(i, n) {
    b[i+1] = b[i] + a[i];
  }
  map<ll, ll> mp;
  rep(i, n+1) mp[b[i]]++;

  ll ans = 0;
  for (auto v:mp) {
    ll t = v.second;
    ans += t*(t-1)/2;
  }
  cout << ans << endl;

  return 0;
}
