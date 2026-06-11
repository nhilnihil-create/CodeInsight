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
  ll N, K;
  cin >> N >> K;

  vll V(N);
  rep(i, N) {
    cin >> V[i];
  }

  ll ans = 0;

  rep(i, K + 1) {  // i個取る時
    if (i > N) {
      continue;
    }

    rep(j, i + 1) {  // 左から取る数
      vll box;
      ll sum = 0;
      rep(p, j) {  // 左から取る
        box.pb(V[p]);
        sum += V[p];
      }

      rep(k, i - j) {  // 右から取る
        ll index = V.size() - 1 - k;
        box.pb(V[index]);
        sum += V[index];
      }
      SORT(box);
      // debug(i);
      // debug(j);
      // debugV(box);
      // ENDL;

      ll count = 0;
      rep(q, box.size()) {
        if (count == K - i) break;
        if (box[q] < 0) {
          sum -= box[q];
          count++;
        } else {
          break;
        }
      }

      ans = max(ans, sum);
    }
  }
  COUT(ans);

  return 0;
}