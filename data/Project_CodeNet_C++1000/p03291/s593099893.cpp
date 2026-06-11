#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;

ll modpow(ll a,ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  string s;
  cin >> s;

  int n = s.size();
  vector<vector<ll>> x(4, vector<ll>(n, 0));
  rep(j, n) {
    if (j) {
      rep(i, 4) {
        x[i][j] += x[i][j - 1];
      }
    }

    if (s[j] == 'A') x[0][j]++;
    else if (s[j] == 'B') x[1][j]++;
    else if (s[j] == 'C') x[2][j]++;
    else if (s[j] == '?') x[3][j]++;
  }

  ll q = x[3][n - 1];
  vector<ll> com(4, 0);
  rep(i, 4) {
    if (q - 3 + i >= 0) com[i] = modpow(3, q - 3 + i);
  }

  ll ans = 0;
  rep(i, n) {
    if (s[i] == 'B') {
      ll res = (x[0][i] * (x[2][n - 1] - x[2][i])) % mod;
      res = (res * com[3]) % mod;
      ans = (ans + res) % mod;
      res = (x[0][i] * (x[3][n - 1] - x[3][i])) % mod;
      res = (res * com[2]) % mod;
      ans = (ans + res) % mod;
      res = (x[3][i] * (x[2][n - 1] - x[2][i])) % mod;
      res = (res * com[2]) % mod;
      ans = (ans + res) % mod;
      res = (x[3][i] * (x[3][n - 1] - x[3][i])) % mod;
      res = (res * com[1]) % mod;
      ans = (ans + res) % mod;
    }
    else if (s[i] == '?') {
      ll res = (x[0][i] * (x[2][n - 1] - x[2][i])) % mod;
      res = (res * com[2]) % mod;
      ans = (ans + res) % mod;
      res = (x[0][i] * (x[3][n - 1] - x[3][i])) % mod;
      res = (res * com[1]) % mod;
      ans = (ans + res) % mod;
      res = ((x[3][i] - 1) * (x[2][n - 1] - x[2][i])) % mod;
      res = (res * com[1]) % mod;
      ans = (ans + res) % mod;
      res = ((x[3][i] - 1) * (x[3][n - 1] - x[3][i])) % mod;
      res = (res * com[0]) % mod;
      ans = (ans + res) % mod;
    }
  }
  cout << ans << endl;
  







  
  return 0;
}