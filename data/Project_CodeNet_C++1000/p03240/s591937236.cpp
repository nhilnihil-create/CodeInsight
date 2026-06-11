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

struct Data {
  ll x;
  ll y;
  ll h;
};

struct Data2 {
  ll x;
  ll y;
  ll h;
  ll flag;
};

signed main() {
  ll N;
  cin >> N;

  vector<Data> D;

  rep(i, N) {
    ll x, y, h;
    cin >> x >> y >> h;
    if (h != 0) {
      D.pb({x, y, h});
    }
  }

  if (D.size() <= 1) {
    cout << D[0].x << " " << D[0].y << " " << D[0].h << endl;
    return 0;
  }

  vector<Data2> same;
  Data d0 = D[0];
  Data d1 = D[1];
  rep(i, 101) {
    rep(j, 101) {
      ll h1 = max((ll)0, d0.h + abs(d0.x - i) + abs(d0.y - j));
      ll h2 = max((ll)0, d1.h + abs(d1.x - i) + abs(d1.y - j));
      if (h1 == h2 && h1 != 0) {
        same.pb({i, j, h1, true});
      }
    }
  }

  rep2(i, 2, D.size()) {
    Data d = D[i];
    rep(j, same.size()) {
      Data2 s = same[j];
      ll h1 = max((ll)0, d.h + abs(d.x - s.x) + abs(d.y - s.y));
      if (h1 != s.h) {
        same[j].flag = false;
      }
    }
  }

  rep(i, same.size()) {
    Data2 s = same[i];
    if (s.flag) {
      cout << s.x << " " << s.y << " " << s.h << endl;
      return 0;
    }
  }
  return 0;
}