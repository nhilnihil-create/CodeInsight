#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){
  string s,t;
  cin>>s>>t;
  int slen=s.length();
  int tlen=t.length();
  int dp[3010][3010];
  rep(i,slen+1)rep(j,tlen+1){
    if(s[i]==t[j]){
      dp[i+1][j+1]=dp[i][j]+1;
    }
    else{
      dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
    }
  }
  //復元
  string ans="";
  int i=slen;
  int j=tlen;
  while(i>=0 && j>=0){
    if(dp[i][j]==dp[i-1][j]){
        i--;
      }
      else if(dp[i][j]==dp[i][j-1]){
        j--;
      }
    else{
      ans=s[i-1]+ans;
      i--;
      j--;
    }
  }
  cout<<ans<<endl;
  return 0;
}


      