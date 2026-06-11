#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, k;
  cin >> n >> k;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll m = 42;
  vector<vl> dp(m + 1, vl(2, -1));
  dp[0][0] = 0;
  rep(i, m) {
    ll cnt = 0;
    rep(j, n) if(a[j] >> (m - 1 - i) & 1) cnt++;
    if(dp[i][1] != -1) dp[i + 1][1] = dp[i][1] * 2 + max(cnt, n - cnt);
    if(k >> (m - 1 - i) & 1) {
      dp[i + 1][0] = dp[i][0] * 2 + n - cnt;
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] * 2 + cnt);
    } else {
      dp[i + 1][0] = dp[i][0] * 2 + cnt;
    }
  }
  cout << max(dp[m][0], dp[m][1]) << endl;
}