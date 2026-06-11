#include <bits/stdc++.h>

using namespace std;

const long mod=1000000007;
const char c[4]={'A','B','C','?'};

int main(){
  string s;
  cin >> s;
  
 long dp[100005][5]={{}};
  dp[s.length()][3]=1;
  
  for(int i=s.length()-1;i>=0;i--){
    for(int j=3;j>=0;j--){
    if(s[i]==c[3]) {
      dp[i][j]=3*dp[i+1][j]+dp[i+1][j+1];
    }
      else {
        dp[i][j]=dp[i+1][j];
        if(s[i]==c[j]) dp[i][j]+=dp[i+1][j+1];
      }
    dp[i][j]%=mod;
    }
 
  }
 cout << dp[0][0] << endl;

}
