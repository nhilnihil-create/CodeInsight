#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

ld dp[305][305][305];
int a[4];
void answer() {
  int n;
  cin >> n;
  rep(i, n) {
    int a_;
    cin >> a_;
    a[a_]++;
  }
  dp[0][0][0] = 0.0;
  repc(i, a[3]) repc(j, a[3]+a[2]-i) repc(k, a[3]+a[2]+a[1]-i-j) {
    if(!i && !j && !k) continue;
    ld e1 = ld(n) / ld(i+j+k);
    ld e2 = 0.0;
    if(i) e2 += i * dp[i-1][j+1][k];
    if(j) e2 += j * dp[i][j-1][k+1];
    if(k) e2 += k * dp[i][j][k-1];
    e2 /= ld(i+j+k);
    dp[i][j][k] = e1 + e2;
  }
  cout << fixed << setprecision(14) << dp[a[3]][a[2]][a[1]] << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}