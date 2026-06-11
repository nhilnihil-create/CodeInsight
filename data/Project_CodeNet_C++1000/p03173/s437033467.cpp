#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
  int n;
  cin >> n;
  vl a(n+1);
  rep(i,n) cin >> a[i+1];
  vvl dp(n+1, vl(n+1));
  vl sum(n+1);
  rep(i,n) sum[i+1] = sum[i] + a[i+1];
  for(int r=2; r<=n; r++){
    for(int l=r-2; l>=0; l--){
      dp[l][r] = dp[l][r-1] + dp[r-1][r] + sum[r] - sum[l];
      for(int k=r-1; k>=0; k--){
        if(l == k) break;
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + sum[r] - sum[l]);
      }
    }
  }
  cout << dp[0][n] << endl;
}
