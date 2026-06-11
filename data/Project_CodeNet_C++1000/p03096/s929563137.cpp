#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int MOD = 1e9 + 7;

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  vector<int> dp(n+1, 0), pos(n+1 + 2e5, -1);
  for(int i = 0; i < n; i++){
    if(i > 0 && a[i-1] == a[i]){
      dp[i+1] = dp[i];
      continue;
    }
    if(pos[a[i]] == -1){
      dp[i+1] = max(1LL, dp[i]);
      pos[a[i]] = i+1;
    }else{
      dp[i+1] = (dp[i] + dp[pos[a[i]]]) % MOD;
      pos[a[i]] = i+1;
    }
  }
  cout << dp[n] << endl;

  return 0;
}
