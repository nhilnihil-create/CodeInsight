#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n;
  cin >> n;
  vl cum(200001, 0LL);
  vl c(n);
  vl dp(n + 1);
  REP(i, n) { cin >> c[i]; }

  c.erase(unique(c.begin(), c.end()), c.end());

  dp[0] = 1LL;
  FOR(i, 1, c.size() + 1) {
    dp[i] = (dp[i - 1] + cum[c[i - 1]]) % MOD;
    cum[c[i - 1]] = (cum[c[i - 1]] + dp[i - 1]) % MOD;
  }
  cout << dp[c.size()] << endl;
}
