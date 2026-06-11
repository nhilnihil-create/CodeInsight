#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define int long long
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

signed main() {
  const int MOD = 1e9+7;
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k; cin >> n >> k;
  vi v(n); for(int& i: v) cin >> i;
  vector<vi> dp(n+1, vi(k+1));
  dp[0][0] = 1;
  vi p(k+2, 1); p[0] = 0;
  vi nxt(k+2);
  rep(i,1,n+1){
    nxt.assign(k+2,0);
    rep(j,0,k+1){
      dp[i][j] = (p[j+1] - p[j-min(j, v[i-1])]) % MOD;
      nxt[j+1] = (nxt[j] + dp[i][j]) % MOD;
    }
    swap(p,nxt);
  }
  cout << (dp[n][k] + MOD) % MOD;
  return 0;
}
