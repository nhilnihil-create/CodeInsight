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
#ifdef _DEBUG
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
#else
#define debug(x)
#endif
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

template <typename T>
void debugV(const vector<T> v) {
#ifdef _DEBUG
  rep(i, v.size()) {
    cout << i << ":" << v[i] << " ";
  }
  cout << endl;
#else
  (void)v;
#endif
}

signed main() {
  ll N, K;
  cin >> N >> K;

  string S;
  cin >> S;

  vector<P> run_length;
  vll sums;

  char before;
  ll count;
  ll all_count = 0;
  rep(i, N) {
    all_count++;
    if (i == 0) {
      before = S[i];
      count = 1;
      // sums.pb(0);
      continue;
    }

    if (S[i] == before) {
      count++;
    } else {
      debug(before);
      debug(count);
      debug(all_count);
      run_length.pb({before, count});
      sums.pb(all_count - 1);
      count = 1;
      before = S[i];
    }
  }
  run_length.pb({before, count});
  sums.pb(all_count);

  debugV(sums);

  ll ans = 0;
  rep(i, run_length.size()) {
    char num = run_length[i].first;
    if (num == '1') {
      if (i + 2 * K <= (ll)sums.size() - 1) {
        if (i == 0) {
          ans = max(ans, sums[i + 2 * K] - 0);
          continue;
        } else {
          ans = max(ans, sums[i + 2 * K] - sums[i - 1]);
          continue;
        }
      } else {
        if (i == 0) {
          ans = max(ans, sums[sums.size() - 1] - 0);
        } else {
          ans = max(ans, sums[sums.size() - 1] - sums[i - 1]);
        }
        continue;
      }
    }
    if (num == '0' && i == 0 && i + 2 * K - 1 <= (ll)sums.size() - 1) {
      ans = max(ans, sums[i + 2 * K - 1] - 0);
      continue;
    }
    if (num == '0' && i == 0 && i + 2 * K - 1 > (ll)sums.size() - 1) {
      ans = max(ans, sums[sums.size() - 1] - 0);
      continue;
    }
  }
  if (ans == 0) {
    COUT(N);
  } else {
    COUT(ans);
  }

  return 0;
}