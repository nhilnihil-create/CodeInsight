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
  ll n,k; cin>>n>>k;
  vector<ll> v(n);
  rep(i, n) cin>>v[i];

  ll ans = 0;
  for (int l=0; l<=n; l++) for (int r=0; l+r<=n; r++) {
    ll c = k-l-r;
    if (c < 0) continue;

    vector<ll> a;
    for (int i=0; i<l; i++) a.push_back(v[i]);
    for (int i=0; i<r; i++) a.push_back(v[n-1-i]);
    sort(a.rbegin(),a.rend());
    while (!a.empty() && a.back() < 0 && c>0) {
      a.pop_back();
      c--;
    }

    ll sum = 0;
    for (auto aa:a) sum += aa;
    ans = max(ans, sum);
  }
  cout << ans << endl;

  return 0;
}
