#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// #undef DEBUG
// #define DEBUG
// DEBUG {{{
// clang-format off
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":", ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream &o, tuple<T...> const &t){ o << "("; _ot<0>(o, t); o << ")"; return o; }
template<class T, class U> ostream & operator<<(ostream &o, pair<T, U> const &p) { o << "(" << p.first << ", " << p.second << ")"; return o; }
#ifdef DEBUG
#if !defined(DEBUG_OUT)
// #define DEBUG_OUT cerr
#endif
#define dump(...) [&](){auto __debug_tap=make_tuple(__VA_ARGS__);DEBUG_OUT<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<__debug_tap<<"\n";}()
template < class T > inline void dump2D(T &d, size_t sizey, size_t sizex) { for(size_t i = 0; i < sizey; i++) { DEBUG_OUT << "\t"; for(size_t j = 0; j < sizex; j++) DEBUG_OUT << d[i][j] << (j + 1 == sizex ? "" : "\t"); DEBUG_OUT << endl; } }
template < class T, class = typename iterator_traits< typename T::iterator >::value_type, class = typename enable_if<!is_same<T, string>::value>::type > ostream &operator<<(ostream &o, const T &a) { o << "{"; for(auto ite = a.begin(); ite != a.end(); ++ite) o << (ite == a.begin() ? "" : ", ") << *ite; o << "}"; return o; }
#else
#define dump(...) (42)
#define dump2D(...) (42)
template < class T, class = typename iterator_traits< typename T::iterator >::value_type, class = typename enable_if<!is_same<T, string>::value>::type > ostream &operator<<(ostream &o, const T &a) { for(auto ite = a.begin(); ite != a.end(); ++ite) o << (ite == a.begin() ? "" : " ") << *ite; return o; }
#endif
// clang-format on
// }}}


int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n, x;
  cin >> n >> x;
  int a[212345];
  for(int i = 0; i < n; i++) cin >> a[i];
  auto f = [&](int k) {
    vector<int> last(k, -1);
    vector<int> cnt(k, 0);
    ll res = 0;
    for(int i = n-1; i >= 0; i--) {
      cnt[i%k]++;
      if(last[i%k] == -1) res += a[i];
      else res += ll(last[i%k] - a[i]) * (cnt[i%k])*(cnt[i%k]);
      last[i%k] = a[i];
    }
    for(int i = 0; i < k; i++){ 
      cnt[i]++;
      if(last[i] != -1) res += (ll) last[i] * cnt[i] * cnt[i];
    }
    return res + (ll) n * x + (ll) x * k;
  };
  int ok = n, ng = 0;
  while(ok-ng > 1) {
    int mid = (ok+ng)/2;
    if(f(mid + 1) - f(mid) >= 0) ok = mid;
    else ng = mid;
  }
  // dump(ok);
  // dump(f(1));
  cout << f(ok) << endl;
  return 0;
}
