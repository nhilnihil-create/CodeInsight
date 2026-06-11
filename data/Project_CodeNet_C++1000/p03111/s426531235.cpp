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
  ll N, A, B, C;
  cin >> N >> A >> B >> C;
  vll L(N);
  rep(i, N) {
    cin >> L[i];
  }
  L.pb(-1);
  L.pb(-1);
  L.pb(-1);
  SORT(L);

  ll ans = INF;
  do {
    if (L[0] == -1) continue;
    ll a = 0;
    ll b = 0;
    ll c = 0;
    ll count = 0;
    ll cost = 0;

    rep(i, N + 3) {
      if (L[i] == -1) {
        count++;
        continue;
      }
      if (count == 0) {
        if (a != 0) cost += 10;
        a += L[i];
      }
      if (count == 1) {
        if (b != 0) cost += 10;
        b += L[i];
      }
      if (count == 2) {
        if (c != 0) cost += 10;
        c += L[i];
      }
    }
    if (a == 0 || b == 0 || c == 0) {
      continue;
    }
    cost += abs(A - a);
    cost += abs(B - b);
    cost += abs(C - c);
    ans = min(ans, cost);
  } while (next_permutation(ALL(L)));

  COUT(ans);

  return 0;
}