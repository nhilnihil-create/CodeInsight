#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
int main() {//BFSなんもわからん
  ll h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }
  vvl dp(h,vl(w,INF));
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#'){
        dp[i][j]=0;
      }
    }
  }
  rep(i,h){
    FOR(j,1,w){
      dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
    }
  }
  rep(i,h){
    for(ll j=w-2;j>=0;j--){
      dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
    }
  }
  FOR(i,1,h){
    rep(j,w){
      dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
    }
  }
  for(ll i=h-2;i>=0;i--){
    rep(j,w){
      dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
    }
  }
  ll ans=-1;
  rep(i,h){
    rep(j,w){
      ans=max(ans,dp[i][j]);
    }
  }
  cout << ans << endl;
}