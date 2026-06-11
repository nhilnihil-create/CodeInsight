#include<iostream>
#include<cmath>
#define MAX_N 200050

using namespace std;

int dp[MAX_N];

int main(){
  int n,k;
  cin >> n >> k;
  int h[MAX_N];
  for(int i=0;i < n;i++) cin >> h[i];
  for(int i=0;i < MAX_N;i++) dp[i] = 1000000000;
  dp[0] = 0;
  
  for(int i=1;i < n;i++){  
    for(int j=max(i-k,0);j < i;j++){
        dp[i] = min(dp[i],dp[j]+abs(h[i] - h[j]));
     }
  }
  cout << dp[n-1] << endl;
  return 0;
}