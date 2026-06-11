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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  string s;
  cin >> s;

  int n = s.length();
  vector<ll> dp(n + 1, INF);
  dp[n] = 0;
  map<int, int> mp;
  mp[0] = n;
  int res = 0;
  repr(i, n - 1) {
    dp[i] = min(dp[i], dp[i + 1] + 1);
    int t = s[i] - 'a';
    res ^= (1 << t);
    if (mp[res]) dp[i] = min(dp[i], dp[mp[res]] + 1);
    rep(j, 26) {
      int res2 = res ^ (1 << j);
      if (mp[res2]) dp[i] = min(dp[i], dp[mp[res2]] + 1);
    }
    if (dp[i] < dp[mp[res]]) mp[res] = i;
  }
  cout << dp[0] << '\n';

  




  
  return 0;
}