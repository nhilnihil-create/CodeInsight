#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 100100100100100100;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll dp[100010][5];

int main(){
  string S;
  cin >> S;
  ll N = S.size();
  dp[0][0] = 1;
  rep(i,N){
    if(S[i] == 'A'){
      dp[i+1][0] += dp[i][0];
      dp[i+1][1] += dp[i][1] + dp[i][0];
      dp[i+1][2] += dp[i][2];
      dp[i+1][3] += dp[i][3];
    }else if(S[i] == 'B'){
      dp[i+1][2] += dp[i][2] + dp[i][1];
      dp[i+1][0] += dp[i][0];
      dp[i+1][1] += dp[i][1];
      dp[i+1][3] += dp[i][3];
    }else if(S[i] == 'C'){
      dp[i+1][3] += dp[i][3] + dp[i][2];
      dp[i+1][0] += dp[i][0];
      dp[i+1][1] += dp[i][1];
      dp[i+1][2] += dp[i][2];
    }else{
      dp[i+1][0] += dp[i][0] * 3;
      dp[i+1][1] += dp[i][1] * 3 + dp[i][0];
      dp[i+1][2] += dp[i][2] * 3 + dp[i][1];
      dp[i+1][3] += dp[i][3] * 3 + dp[i][2];
    }
    dp[i+1][0] %= MOD;
    dp[i+1][1] %= MOD;
    dp[i+1][2] %= MOD;
    dp[i+1][3] %= MOD;
  }
  cout << dp[N][3] << endl;
}
