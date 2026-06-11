#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 2e5 + 5;
const ll mod = 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n;
  cin >> n;
  vector < ll > c(n + 1, 0), sum(MAXN, 0), dp(n + 1, 0);
  for(int i = 1; i <= n; i++) cin >> c[i];
  dp[0] = 1;
  for(int i = 1; i <= n; i++){
    dp[i] = sum[c[i]];
    if(c[i] != c[i - 1]){
      dp[i] += dp[i - 1];
      dp[i] %= mod;
      sum[c[i]] += dp[i - 1];
      sum[c[i]] %= mod;
    }
  }

  cout << dp[n] << '\n';
}
