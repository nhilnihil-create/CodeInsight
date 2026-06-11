#include <bits/stdc++.h>

using namespace std;
const int MAX_BIT=50;

int main(){
  long long n, k, dp[MAX_BIT+1][2], c[MAX_BIT+1];
  cin >> n >> k;
  memset(c, 0, sizeof(c));
  memset(dp, 0, sizeof(dp));
  for(int i=0;i<n;i++){
    long long a;cin >> a;
    for(int j=0;j<=MAX_BIT;j++){
      if((a>>j)&1)c[j]++;
    }
  }
  dp[0][0]=0;
  dp[0][1]=0;
  for(int i=1;i<=MAX_BIT;i++){
    if(dp[i-1][0]==0){
      if(k>>(MAX_BIT-i)&1){
        dp[i][0]=c[MAX_BIT-i];
        dp[i][1]=(dp[i-1][1]<<1)+n-c[MAX_BIT-i];
      }
      else{
        dp[i][1]=(dp[i-1][1]<<1)+c[MAX_BIT-i];
      }
    }
    else{
      dp[i][0]=max(dp[i][0], (dp[i-1][0]<<1)+c[MAX_BIT-i]);
      dp[i][0]=max(dp[i][0], (dp[i-1][0]<<1)+n-c[MAX_BIT-i]);
      if(k>>(MAX_BIT-i)&1){
        dp[i][0]=max(dp[i][0], (dp[i-1][1]<<1)+c[MAX_BIT-i]);
        dp[i][1]=(dp[i-1][1]<<1)+n-c[MAX_BIT-i];
      }
      else{
        dp[i][1]=(dp[i-1][1]<<1)+(c[MAX_BIT-i]);
      }
    }
  }
  cout << max(dp[MAX_BIT][1], dp[MAX_BIT][0]) << endl;
}

