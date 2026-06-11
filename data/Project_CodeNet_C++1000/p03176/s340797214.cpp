#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using VVVld = vector<VVld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}


template<typename T>
struct BIT {
  int n; vector<T> d;
  BIT(int n=0) : n(n), d(n+1) {}
  void add(int i, T a=1) {
    for (i++; i <= n; i += i & -i) chmax(d[i], a);
  }
  // sum [0, i)
  T sum(int i) {
    if (i == 0) return 0;
    T x = 0;
    for (; i > 0; i -= i & -i) chmax(x, d[i]);
    return x;
  }
};


int main() {
  int n; cin >> n;
  V h(n);
  Vll a(n);
  rep(i, n) cin >> h[i];
  rep(i, n) cin >> a[i];

  BIT<ll> dp(n+1);

  rep(i, n) dp.add(h[i], dp.sum(h[i]) + a[i]);
  
  ll ans = dp.sum(n+1);
  cout << ans << endl;
  return 0;
}
