#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// #undef DEBUG
// #define DEBUG
/// {{{ DEBUG --- ///
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if(&o == &cerr) { o << '{'; for(size_t i = 0; i < v.size(); i++) o << v[i] << (i + 1 != v.size() ? ", " : ""); o << "}"; } else { for(size_t i = 0; i < v.size(); i++) o << v[i] << (i + 1 != v.size() ? " " : ""); } return o; }
#ifdef DEBUG
#ifdef USE_COUT
#define dump(...) (cout<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<make_tuple(__VA_ARGS__)<<"\n")
#else
#define dump(...) (cerr<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<make_tuple(__VA_ARGS__)<<"\n")
#endif
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":", ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream &o, tuple<T...> const &t){ o << "("; _ot<0>(o, t); o << ")"; return o; }
template<class T, class U> ostream & operator<<(ostream &o, pair<T, U> const &p) { o << "(" << p.first << ", " << p.second << ")"; return o; }
#else
#define dump(...) (0)
#endif
/// }}}--- ///

ll S(ll x) {
  ll s = 0;
  while(x) s += x % 10, x /= 10;
  return s;
}

ll fc(ll a, ll b) { return a * S(b) > b * S(a); }

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  ll k; cin >> k;
  ll t = 1;
  vector<ll> v(15);
  vector<ll> b(15);
  // for(int i = 0; i < 15; i++) {
  //   ll ok = 1, ng = 1e15 / t;
  //   while(ng - ok > 1) {
  //     ll mid = (ok + ng) / 2;
  //     ll mm = mid;
  //     if(mid % 10 == 9) mm++;
  //     ll n = mm * t + t - 1;
  //     if(S(n) * (n + t) <= n * (S(n + t))) ok = mid; else {ng = mid;if(i == 1)dump(ng, mm, n);}
  //   }
  //   v[i] = ok;
  //   b[i] = t;
  //   t *= 10;
  // }
  // dump(v, b);
  int head = 0;
  vector<ll> ans;
  ll n = 1;
  t = 1;
  while(n <= 1e15) {
    ans.emplace_back(n);
    if(ans.size() >= k) break;
    while(t <= 1e15 && fc(n + t, n + t + t)) t *= 10;
    n += t;
  }
  for(int i = 0; i < k; i++) cout << ans[i] << endl;
}

