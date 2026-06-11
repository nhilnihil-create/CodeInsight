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
template < class T > ostream &operator<<(ostream &o, const stack<T> &a) { o << "{"; for(auto tmp = a; tmp.size(); tmp.pop()) o << (a.size() == tmp.size() ? "" : ", ") << tmp.top(); o << "}"; return o; }
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

const int D = 31;

void NO () {
  cout << -1 << endl;
  exit(0);
}

pair<ll, ll> check(vector<ll> &ans, string &str) {
  static map<char, int> dx {
    {'D', 0},
    {'U', 0},
    {'L', -1},
    {'R', +1},
  };
  static map<char, int> dy {
    {'D', -1},
    {'U', +1},
    {'L', 0},
    {'R', 0},
  };
  int x = 0, y = 0;
  for(int i = 0; i < D; i++) {
    x += dx[str[i]] * ans[i];
    y += dy[str[i]] * ans[i];
  }
  return {x, y};
}

vector<int> sol(int u){
  vector<int> res(D);
  int f = 0;
  for(int j = D - 1; j >= 0; j--) {
    int g = u & (1 << j);
    if(f) {
      if(g) {
        f = 0;
      } else {
      }
    } else {
      res[j] = 1;
      if(g) {
      } else {
        f = 1;
      }
    }
  }
  return res;
}

ll x[1000], y[1000];

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n;
  cin >> n;
  const ll inf = 2e9;
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for(int i = 0; i < n; i++) if((x[0] + y[0] + inf)%2!=(x[i] + y[i] + inf)%2) NO();
  vector<ll> ans(D);
  for(int i = 0; i < D; i++) ans[i] = (1 << i);
  // - : L D
  if((x[0] + y[0] + inf) % 2 == 0) {
    ans.emplace_back(1);
    for(int i = 0; i < n; i++) x[i]++;
  }
  cout << ans.size() << endl;
  cout << ans << endl;
  string r(ans.size(), 'L');
  string mp = "LDUR";
  for(int i = 0; i < n; i++) {
    string str = r;
    int u = x[i] + y[i], v = x[i] - y[i];
    int uneg = u < 0, vneg = v < 0;
    if(uneg) u *= -1;
    if(vneg) v *= -1;
    auto du = sol(u);
    auto dv = sol(v);
    for(int j = 0; j < D; j++) {
      str[j] = mp[((du[j] ^ uneg) << 1) + (dv[j] ^ vneg)];
    }
    dump(x[i], y[i]);
    dump(check(ans, str));
    // assert(make_pair(x[i], y[i]) == check(ans, str));
    cout << str << endl;
  }
  return 0;
}
