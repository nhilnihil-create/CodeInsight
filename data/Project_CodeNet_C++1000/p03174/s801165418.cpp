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
  cin >> n;
  vvi a(n,vi(n));
  rep(i,n){
    rep(j,n) cin >> a[i][j];
  }
  vl dp(1<<n,0);
  dp[0] = 1;
  REP(tmp,1,1<<n){
    int m = __builtin_popcount(tmp);
    rep(i,n){
      if(((1<<i)&tmp) && a[m-1][i]){
        dp[tmp] += dp[tmp^(1<<i)];
        dp[tmp] %= MOD;
      }
    }
  }
  cout << dp[(1<<n)-1] << endl;
}
