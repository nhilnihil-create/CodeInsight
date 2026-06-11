#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(int i=int(m-1); i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) a.begin(), a.end()
#define fst first
#define snd second
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}
inline int Log2(ll x) {int k; for(k=0; x>0; ++k) x>>=1; return k;} // number of binary digits
template<typename T> inline int count_between(vector<T>& a, T l, T r) {
  return lower_bound(all(a), r) - lower_bound(all(a), l); // [l, r)
}
template<typename T> istream& operator>>(istream& is, vector<T>& v) {
  rep(i, v.size()) is >> v[i]; return is;
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
  rep(i, v.size()) os << v[i] << " "; os << endl; return os;
}
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;


int main() {
  ll n; cin >> n;
  V l(n), r(n);
  rep(i, n) cin >> l[i] >> r[i];
  sort(all(l), greater<int>());
  sort(all(r));

  Vll sl(n+1), sr(n+1);
  rep(i, n) sl[i+1] = sl[i] + l[i];
  rep(i, n) sr[i+1] = sr[i] + r[i];

  ll ans = 0;
  rep(i, n) chmax(ans, sl[i]-sr[i]);
  rep(i, n-1) chmax(ans, sl[i+1]-sr[i]);
  rep(i, n-1) chmax(ans, sl[i]-sr[i+1]);

  ans *= 2;
  cout << ans << endl;
  return 0;
}
