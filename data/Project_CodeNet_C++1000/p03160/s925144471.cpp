#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;

  vector<int> h(n+1);
  rep(i,n) cin >> h[i+1];

  vector<int> dp(n+1,0);

  for(int i = 1; i <= n; i++){
    if(i==1){
      dp[i] = 0;
      continue;
    }
    if(i==2){
      dp[i] = abs(h[i] - h[i - 1]);
      continue;
    }
    int cost1 = dp[i-1] + abs(h[i] - h[i-1]);
    int cost2 = dp[i-2] + abs(h[i] - h[i-2]);
    dp[i] = min(cost1,cost2);
  }

  cout << dp[n] << endl;

  return 0;
}
