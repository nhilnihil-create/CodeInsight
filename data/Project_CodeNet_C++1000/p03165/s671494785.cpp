#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin>>s>>t;
  int sl=s.length();
  int tl=t.length();
  int dp[3010][3010];
  dp[0][0]=0;


  for(int i=0;i<sl;i++){
    for(int j=0;j<tl;j++){
      if(s[i]==t[j]){
        dp[i+1][j+1]=dp[i][j]+1;
      }else{
        dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
      }
    }
  }
  //復元
  string ans="";
  int i=sl;
  int j=tl;
  while(i>0 && j>0){
    if(dp[i][j]==dp[i][j-1]){
      j--;
    }
    else if(dp[i][j]==dp[i-1][j]){
      i--;
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

      