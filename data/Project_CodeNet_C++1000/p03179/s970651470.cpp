#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
  int n;
  string s;
  cin >> n >> s;
  vvl dp(n+1,vl(n+1,0));
  rep(i,n) dp[0][i] = 1;
  rep(i,n-1){
    vl sum(n+1,0);
    rep(j,n){
      sum[j+1] = (sum[j] + dp[i][j]) % MOD;
    }
    rep(j,n-i-1){
      if(s[i] == '<'){
        dp[i+1][j] = (sum[n] - sum[j+1] + MOD) % MOD;
      }else{
        dp[i+1][j] = sum[j+1] % MOD;
      }
    }
  }
  /*rep(i,n){
    rep(j,n) cout << dp[i][j] << " ";
    cout << endl;
  }*/
  cout << dp[n-1][0] << endl;
}