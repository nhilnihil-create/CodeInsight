#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n,k;
  cin >> n >> k;

  vector<int> h(n+1);
  rep(i,n) cin >> h[i+1];

  vector<int> dp(n+1,0);
  dp[1] = 0;

  for(int i = 2; i <= n; i++){
    dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
    for(int j = 1; j <= k; j++){
      if(i-j<1) break;
      dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
    }
  }

  cout << dp[n] << endl;

  return 0;
}
