#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll Ep(int a){
  if(a == 0) return 1;
  if(a == 1) return 2;
  ll num = Ep(a/2);
  if(a%2) return num *num *2;
  else return num *num;
}

int main(){
  int n;
  ll k, ai;
  cin >> n >> k;
  vector<int> cnt(45,0);
  for(int i=0; i<n; ++i){
    cin >> ai;
    int keta = 0;
    while(ai > 0){
      cnt[keta] += ai%2;
      ai /= 2;
      ++keta;
    }
  }
  vector<vector<ll>> dp(45, vector<ll>(2,0));
  for(int i=43; i>=0; --i){
    ll num = Ep(i);
    if(dp[i+1][0]){
      dp[i][0] = dp[i+1][0] +num *max(cnt[i],n-cnt[i]);
    }
    if(k >= num){
      dp[i][1] = dp[i+1][1] +num *(n-cnt[i]);
      dp[i][0] = max(dp[i][0],dp[i+1][1] +num *cnt[i]);
    }else{
      dp[i][1] = dp[i+1][1] +num *cnt[i];
    }
    if(k >= num) k -= num;
  }
  ll ans = max(dp[0][0], dp[0][1]);
  cout << ans << endl;
}