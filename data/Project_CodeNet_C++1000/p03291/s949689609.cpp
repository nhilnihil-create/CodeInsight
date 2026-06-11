#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;

const int mod=1e9+7;

int main(){
  string S;
  cin >> S;
  vector<vector<ll>> dp(S.size()+1, vector<ll>(4));
  dp[0][0]=1;
  rep(i,S.size()){
    if(S[i]=='A' || S[i]=='?'){
      rep(j,4)
        dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
      dp[i+1][1] = (dp[i+1][1]+dp[i][0])%mod;
    }
    if(S[i]=='B' || S[i]=='?'){
      rep(j,4)
        dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
      dp[i+1][2] = (dp[i+1][2]+dp[i][1])%mod;
    }
    if(S[i]=='C' || S[i]=='?'){
      rep(j,4)
        dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
      dp[i+1][3] = (dp[i+1][3]+dp[i][2])%mod;
    }
  }
  cout << dp[S.size()][3] << endl;
  return 0;
}