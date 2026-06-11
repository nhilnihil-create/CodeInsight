#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

ll modpow(ll a,ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll modinv(ll a) {
  return modpow(a, mod - 2);
}

ll inv[100100];

void init() {
  FOR(i, 1, 100100) inv[i] = modinv(i);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  init();

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0, res = 0;
  FOR(i, 1, n + 1) res = (res + inv[i]) % mod;
  rep(i, n) {
    ans = (ans + res * a[i]) % mod;
    res = (res - inv[n - i] + inv[i + 2] + mod) % mod;
  }
  FOR(i, 1, n + 1) ans = (ans * i) % mod;
  cout << ans << '\n';


  

  




  
  return 0;
}