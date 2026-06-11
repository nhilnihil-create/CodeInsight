#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

const ll INF=1e18;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  ll A,B;
  cin>>N>>A>>B;
  vector<int> P(N);
  rep(i,N) cin>>P[i];

  vector<vector<ll>> dp(N+1,vector<ll> (N+1,INF));
  dp[0][0]=0;
  for(int i=0;i<N;i++){
      for(int j=0;j<=N;j++){
          if(dp[i][j]==INF) continue;
          {
              ll neco=A;
              if(P[i]<j) neco=B;
              chmin(dp[i+1][j],dp[i][j]+neco);
          }

          {
              if(j<P[i]) chmin(dp[i+1][P[i]],dp[i][j]);
          }
      }
  }

  ll ans=INF;
  rep(i,N+1) chmin(ans,dp[N][i]);
  cout<<ans<<endl;

  return 0;
}
