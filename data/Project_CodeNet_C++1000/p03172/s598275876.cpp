#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll MOD = 1000000007;
  int n, k;
  cin >> n >> k;
  vi a(n+1);
  rep(i,n) cin >> a[i+1];
  vector<vector<ll>> dp(n+1, vector<ll>(k+1));
  dp[0][0] = 1;
  for(int i=1; i<=n; i++){
    vector<ll> sum(k+2);
    sum[0] = 0;
    for(int j=1; j<=k+1; j++) sum[j] = (sum[j-1] + dp[i-1][j-1]) % MOD;
    for(int j=0; j<=k; j++) dp[i][j] = (sum[j+1] - sum[max(0, j-a[i])] + MOD) % MOD;
  }
  cout << dp[n][k] << endl;
}
