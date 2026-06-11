#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define pb push_back
#define COUT(x) cout << (x) << endl
#define COUTF(x) cout << setprecision(15) << (x) << endl
#define ENDL cout << endl
#define DF(x) x.erase(x.begin())  // 先頭文字削除
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(ALL(x))
#define init() \
  cin.tie(0);  \
  ios::sync_with_stdio(false)
#define debug(x) cerr << "[debug] " << #x << ": " << x << endl;
#define debugV(v)                       \
  cerr << "[debugV] " << #v << ":";     \
  rep(i, v.size()) cerr << " " << v[i]; \
  cerr << endl;
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using P = pair<ll, ll>;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ld PI = 3.141592653589793238462643383279;
ll get_digit(ll x) {
  return to_string(x).size();
}

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

vector<P> factorize(ll n) {
  vector<P> result;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      result.pb({i, 0});
      while (n % i == 0) {
        n /= i;
        result.back().second++;
      }
    }
  }
  if (n != 1) {
    result.pb({n, 1});
  }
  return result;
}

vll divisor(ll n) {
  vll ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  SORT(ret);
  return (ret);
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  init();
  ll N;
  cin >> N;

  ll M = 0;
  ll A = 0;
  ll R = 0;
  ll C = 0;
  ll H = 0;

  rep(i, N) {
    string s;
    cin >> s;
    if (s[0] == 'M') M++;
    if (s[0] == 'A') A++;
    if (s[0] == 'R') R++;
    if (s[0] == 'C') C++;
    if (s[0] == 'H') H++;
  }

  ll ans = 0;
  ans += M * A * R;
  ans += M * A * C;
  ans += M * A * H;
  ans += M * R * C;
  ans += M * R * H;
  ans += M * C * H;
  ans += A * R * C;
  ans += A * R * H;
  ans += A * C * H;
  ans += R * C * H;
  COUT(ans);
  return 0;
}