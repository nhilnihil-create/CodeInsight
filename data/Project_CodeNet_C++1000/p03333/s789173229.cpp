#pragma region template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template <typename T>
using pqrev = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for (ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for (ll i = (b)-1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
//*
constexpr ll MOD = 1e9 + 7;
/*/
constexpr ll MOD = 998244353;
//*/
constexpr ll INF = 1e+18;
constexpr ld EPS = 1e-12L;
constexpr ld PI = 3.14159265358979323846L;
constexpr ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
constexpr ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
template <typename S, typename T>
constexpr bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T>
constexpr bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
template <typename T>
bool print_(const T &a) {
  cout << a;
  return true;
}
template <typename T>
bool print_(const vector<T> &vec) {
  for (auto &a : vec) {
    cout << a;
    if (&a != &vec.back()) {
      cout << " ";
    }
  }
  return false;
}
template <typename T>
bool print_(const vector<vector<T>> &vv) {
  for (auto &v : vv) {
    for (auto &a : v) {
      cout << a;
      if (&a != &v.back()) {
        cout << " ";
      }
    }
    if (&v != &vv.back()) {
      cout << "\n";
    }
  }
  return false;
}
void print() { cout << "\n"; }
template <typename Head, typename... Tail>
void print(Head &&head, Tail &&... tail) {
  bool f = print_(head);
  if (sizeof...(tail) != 0) {
    cout << (f ? " " : "\n");
  }
  print(forward<Tail>(tail)...);
}
#pragma endregion

void Pr(bool f){
  cout << (f ? "Yes" : "No") << "\n";
  exit(0);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vll l(n), r(n);
  rep(i, n){
    cin >> l[i] >> r[i];
  }
  set<tuple<ll, ll, ll>> stl, str;
  rep(i, n){
    stl.emplace(l[i], r[i], i);
    str.emplace(r[i], l[i], i);
  }
  if(1/**min_element(ALL(r)) > 0 || *max_element(ALL(l)) < 0*/){
    stl.emplace(0, 0, n);
    str.emplace(0, 0, n);
  }
  ll ans = 0;
  while(stl.size()){
    dump(stl, str);
    auto a = *str.begin();
    auto b = *stl.rbegin();
    dump(get<0>(b), get<0>(a), ans);
    if(get<0>(a) < get<0>(b)){
      ans += 2*(get<0>(b) - get<0>(a));
      tuple<ll, ll, ll> c = tuple<ll, ll, ll>{get<1>(a), get<0>(a), get<2>(a)};
      tuple<ll, ll, ll> d = tuple<ll, ll, ll>{get<1>(b), get<0>(b), get<2>(b)};
      stl.erase(c);
      stl.erase(b);
      str.erase(a);
      str.erase(d);
    }else{
      break;
    }
  }
  print(ans);
}
