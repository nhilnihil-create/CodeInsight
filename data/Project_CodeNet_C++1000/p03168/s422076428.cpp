#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define For(i, a) for (int i=0; i<a; i++)
#define FORR(i,a,b) for (int i = a; i >= b; i--)
#define Forr(i,a) for (int i = a; i >= 0; i--)

#define deb(...) cerr << "[" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__)
void DBG() { cerr << "]\n";}
template<typename T, typename ...Args> void DBG(T first, Args... args)
{cerr << first; if(sizeof...(args))cerr<<", "; DBG(args...); }

void solve(){
  int n; cin >> n;
  double p[n+1];
  For(i,n)cin >> p[i];
  double dp[2][2][n+2];
  memset(dp,0,sizeof(dp));
  dp[0][0][1] = p[0];
  dp[0][1][0] = (1.0-p[0]);
  int flag = 0;
  For(i,n){
    For(j,n){
      For(k,2){
        if(k==0){
          dp[1-flag][k][j+1] = p[i+1]*(dp[flag][k][j]+dp[flag][1-k][j]);
        }
        else{
          dp[1-flag][k][j] = (1.0-p[i+1])*(dp[flag][k][j]+dp[flag][1-k][j]);
        }
      }
    }
    flag = 1-flag;
  }
  long double ans = 0.0;
  FOR(i,n/2+1,n+1){
    For(j,2){
      ans += dp[1-flag][j][i];
    }
  }
  cout << fixed << setprecision(10) << ans <<"\n";
}

int32_t main(){
  ios_base:: sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  for(int tt=1;tt<=t;tt++){
    solve();
  }
}