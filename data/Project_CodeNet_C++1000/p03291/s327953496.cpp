//from https://coderecipe.org/atcoder/abc104_d.html#%E5%8F%82%E8%80%83%E3%81%AB%E3%81%AA%E3%81%A3%E3%81%9F%E3%82%B3%E3%83%BC%E3%83%89
#include<bits/stdc++.h>

#define rep(i,n) for(ll i = 0; i < (n); i++)
#define ll long long
#define MOD 1000000007

using namespace std;

ll dp[100011][4];

int main(){
  string s;cin>>s;
  dp[0][0]=1;

  rep(i, s.size()){

    if(s[i]=='A'){
      rep(j,4){
        dp[i+1][j]=dp[i][j];
      }
      dp[i+1][1]=(dp[i][1] + dp[i][0])%MOD;
    }

    if(s[i]=='B'){
      rep(j,4){
        dp[i+1][j]=dp[i][j];
      }
      dp[i+1][2]=(dp[i][2] + dp[i][1])%MOD;
    }

    if(s[i]=='C'){
      rep(j,4){
        dp[i+1][j]=dp[i][j];
      }
      dp[i+1][3]=(dp[i][3] + dp[i][2])%MOD;      
    }

    if(s[i]=='?'){
      dp[i+1][0]=3*dp[i][0]%MOD;
      rep(j,3){
        dp[i+1][j+1]=(dp[i][j] + 3*dp[i][j+1])%MOD;
      }
    }

  }

  cout<<dp[s.size()][3]%MOD<<endl;

  return 0;
}
