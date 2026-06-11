#include <bits/stdc++.h>
using namespace std;

int dp[100010];
int main(){
  dp[0]=0;
  for(int n=1;n<=100000;n++){
    dp[n]=100000;
    int power=1;
    while(power<=n){
      dp[n]=min(dp[n],dp[n-power]+1);
      power*=6;
    }
    power=1;
    while(power<=n){
      dp[n]=min(dp[n],dp[n-power]+1);
      power*=9;
    }
  }
  int n;
  cin>>n;
  cout<<dp[n];

}