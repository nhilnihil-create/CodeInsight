#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll dp[100005][4]={0};
int main(){
  string s;
  cin>>s;
  int n=s.length();
  dp[0][0]=1;
  for(int i=0;i<n;i++){
    if(s[i]=='?'){
      for(int j=0;j<4;j++) dp[i+1][j]+=dp[i][j]*3;
      dp[i+1][1]+=dp[i][0];
      dp[i+1][2]+=dp[i][1];
      dp[i+1][3]+=dp[i][2];
    }
    else{
      for(int j=0;j<4;j++){
        dp[i+1][j]+=dp[i][j];
      }
      if(s[i]=='A') dp[i+1][1]+=dp[i][0];
      if(s[i]=='B') dp[i+1][2]+=dp[i][1];
      if(s[i]=='C') dp[i+1][3]+=dp[i][2];
    }
    for(int j=0;j<4;j++) dp[i+1][j]%=mod;
  }

/*  for(int j=0;j<4;j++){
    for(int i=0;i<=n;i++) cout<<dp[i][j]<<" ";
    cout<<endl;
  } */
  cout<<dp[n][3]<<endl;
}
