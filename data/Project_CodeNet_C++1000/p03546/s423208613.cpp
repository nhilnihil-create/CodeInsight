#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  vin pp(10);//i-1が何個あるか
  
 int h,w;
  cin>>h>>w;
  vector<vin> c(10,vin(10));
  rep(i,0,10){
   rep(j,0,10) cin>>c[i][j]; 
  }
  vector<vin> a(h,vin(w));
  rep(i,0,h){
    rep(j,0,w) {
      cin>>a[i][j]; 
      if(a[i][j]!=-1){
        pp[a[i][j]]++;
      }
    }
  }
  int dp[11][11];//i回変換して1に行く最小値　jから
  rep(i,0,11){
   rep(j,0,11) dp[i][j]=inf; 
  }
  rep(i,0,10){
   dp[1][i]=c[i][1]; 
  }
  dp[0][1]=0;
  rep(i,2,10){
    rep(j,0,10){
      
      rep(k,0,10){
        
        chmin(dp[i][j],dp[i-1][k]+c[j][k]);
      }
    }
  }
  vin mn(10);
  rep(i,0,10) mn[i]=inf;
  rep(i,0,10){
    rep(j,0,10) chmin(mn[i],dp[j][i]);
  }
  int ans=0;
  rep(i,0,10){
    ans+=(pp[i]*mn[i]);
  }
  cout<<ans<<endl;
}