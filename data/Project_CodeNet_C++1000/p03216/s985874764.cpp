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
//
constexpr ll MOD = 1e9 + 7;
/*/
const ll MOD = 998244353;
//*/
constexpr ll INF = 1e+18;
constexpr ld EPS = 1e-12L;
constexpr ld PI = 3.14159265358979323846L;
constexpr ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
constexpr ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
template <typename S, typename T>
inline bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T>
inline bool chmin(S &a, const T &b) {
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

// Binary Indexed Tree 0-indexed
struct BIT0 {
  ll n;
  vector<ll> bit;
  BIT0(ll n) : n(n), bit(n, 0) {}
  void add(ll a, ll w) {
    for (; a < n; a |= a + 1) {
      bit[a] += w;
    }
  }
  // v: 0-indexed, size = n
  void build(const vector<ll> &v) {
    n = v.size();
    bit = v;
    ll unit = 1;
    while (unit * 2 < n) {
      for (int i = unit * 2 - 1; i < n; i += unit * 2) {
        bit[i] += bit[i - unit];
      }
      unit <<= 1;
    }
  }
  ll sum(ll a) {
    ll ret = 0;
    for (; a >= 0; a = (a & (a + 1)) - 1) {
      ret += bit[a];
    }
    return ret;
  }
  // [a, b]
  ll sum(ll a, ll b) {
    return sum(b) - sum(a - 1);
  }
};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll Q;
  cin >> Q;
  rep(QQ, Q){
    ll k;
    cin >> k;
    //BIT0 bt(n);
    ll mcnt = 0;
    ll dsum = 0;
    ll dcnt = 0;
    ll ans = 0;
    rep(i, n){
      if(i >= k){
        switch(s[i-k]){
        case 'D':
          dcnt--;
          dsum -= mcnt;
          break;
        case 'M':
          mcnt--;
          break;
        case 'C':
          break;
        }
      }
      switch(s[i]){
      case 'D':
        dcnt++;
        break;
      case 'M':
        mcnt++;
        dsum += dcnt;
        break;
      case 'C':
        ans += dsum;
        break;
      }
    }
    print(ans);
  }
}
