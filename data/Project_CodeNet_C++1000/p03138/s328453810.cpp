#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  ll n, K; cin >> n >> K;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
  vector<vector<ll> > dp(50, vector<ll> (2, -1));
  dp[40][0] = 0;
  for(int d = 45; d >= 0; d--){
   ll num = 0, mask = 1LL << d;
   for(int j = 0; j < n; j++) if(a[j] & mask) num++;
   if(dp[d + 1][1] != -1) dp[d][1] = max(dp[d][1], dp[d + 1][1] + mask * max(num, n - num));
   if(dp[d + 1][0] != -1){
     if(K & mask){
       dp[d][1] = max(dp[d][1], dp[d + 1][0] + mask * num);
       dp[d][0] = max(dp[d][0], dp[d + 1][0] + mask * (n - num));
     }
     else dp[d][0] = max(dp[d][0], dp[d + 1][0] + mask * num);
   }
  }
  cout << max(dp[0][0], dp[0][1]) << endl;
}
