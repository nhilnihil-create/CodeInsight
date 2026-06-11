#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const ll MOD = 1000000007;

ll dp[100005][4][3];

int main(){
  string S;
  cin >> S;

  if(S[0]=='A' || S[0] == '?'){
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
  }
  if(S[0]=='B' || S[0] == '?'){
    dp[0][0][1] = 1;
  }
  if(S[0]=='C' || S[0] == '?'){
    dp[0][0][2] = 1;
  }
  REP(i,1,S.size()){
    rep(j,4){
      if(S[i] == 'A' || S[i] == '?'){
        dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2];
        dp[i][j][0] %= MOD;
      }
      if(S[i] == 'B' || S[i] == '?'){
        dp[i][j][1] += dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2];
        dp[i][j][1] %= MOD;
      }
      if(S[i] == 'C' || S[i] == '?'){
        dp[i][j][2] += dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2];
        dp[i][j][2] %= MOD;
      }
    }
    if(S[i] == 'A' || S[i] == '?'){
      dp[i][1][0] += dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2];
      dp[i][1][0] %= MOD;
    }
    if(S[i] == 'B' || S[i] == '?'){
      dp[i][2][1] += dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2];
      dp[i][2][1] %= MOD;
    }
    if(S[i] == 'C' || S[i] == '?'){
      dp[i][3][2] += dp[i-1][2][0] + dp[i-1][2][1] + dp[i-1][2][2];
      dp[i][3][2] %= MOD;
    }
  }

  /*
  rep(i,4){
    rep(k,3){
      rep(j,S.size()){
        cout << dp[j][i][k] << " ";
      }
      cout << endl;
    }

    cout << endl;
    cout << endl;
  }
   */
  ll ret = dp[S.size()-1][3][0] + dp[S.size()-1][3][1] + dp[S.size()-1][3][2];
  ret %= MOD;

  cout << ret << endl;
  
  return 0;
}
