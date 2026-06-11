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
#define Init() \
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
constexpr double PI = 3.141592653589793238462643383279;
ll getDigit(ll x) {
  return x == 0 ? 1 : log10(x) + 1;
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
  Init();
  ll N, H;
  cin >> N >> H;

  vector<P> katana(N);
  ll katana_m = 0;
  rep(i, N) {
    ll a, b;
    cin >> a >> b;
    katana[i] = {b, a};
    if (a > katana_m) {
      katana_m = a;
    }
  }

  SORT(katana);

  ll ans = 0;
  repr(i, N - 1) {
    if (katana[i].first > katana_m) {
      ans++;
      H -= katana[i].first;
    }
    if (H <= 0) {
      COUT(ans);
      return 0;
    }
  }

  if (H % katana_m == 0) {
    ans += H / katana_m;
  } else {
    ans += H / katana_m + 1;
  }

  COUT(ans);
  return 0;
}