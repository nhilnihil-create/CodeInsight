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
  priority_queue<P> pql0, pql;
  priority_queue<P, vector<P>, greater<P>> pqr0, pqr;
  rep(i, n) {
    int l, r; cin >> l >> r;
    pql0.push(P(l, i));
    pqr0.push(P(r, i));
  }

  pql = pql0;
  pqr = pqr0;

  int now = 0;
  ll ans1 = 0;
  vector<bool> used(n, false);
  int cnt = 0;
  while (!pql.empty() && !pqr.empty()) {
    int x, i;
    if (cnt%2) {
      tie(x, i) = pql.top(); pql.pop();
      if (used[i]) continue;
      if (now < x) {
        ans1 += x-now;
        now = x;
      }
    }
    else {
      tie(x, i) = pqr.top(); pqr.pop();
      if (used[i]) continue;
      if (now > x) {
        ans1 += now-x;
        now = x;
      }
    }
    used[i] = true;
    ++cnt;
  }
  ans1 += abs(now);

  ll ans = ans1;

  pql = pql0;
  pqr = pqr0;
  
  now = 0;
  ans1 = 0;
  used = vector<bool>(n, false);
  cnt = 1;
  while (!pql.empty() && !pqr.empty()) {
    int x, i;
    if (cnt%2) {
      tie(x, i) = pql.top(); pql.pop();
      if (used[i]) continue;
      if (now < x) {
        ans1 += x-now;
        now = x;
      }
    }
    else {
      tie(x, i) = pqr.top(); pqr.pop();
      if (used[i]) continue;
      if (now > x) {
        ans1 += now-x;
        now = x;
      }
    }
    used[i] = true;
    ++cnt;
  }
  ans1 += abs(now);
  
  chmax(ans, ans1);
  cout << ans << endl;
  return 0;
}
