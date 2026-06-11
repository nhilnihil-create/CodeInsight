#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;

signed main(){
  int n;cin>>n;
  vector<vector<int>> a(n,vector<int>(n,0));
  rep(i,n){
      rep(j,n){
          cin>>a[i][j];
      }
  }
  int num=(1ll<<n);
  vector<int> dp(num,0);
  rep(i,num){
      int buf=0;
      rep(j,n){
          if(i&(1ll<<j)){
              rep(k,n){
                  if(i&(1ll<<k)){
                      buf+=a[k][j];
                  }
              }
          }
      }
      dp[i]=buf/2;
  }
  rep(i,num){
      //printf("dp[%lld] = %lld\n",i,dp[i]);
  }
  rep(i,num){
      for(int j=i;j>0;--j){
          j=j&i;
          int buf=dp[j]+dp[i-j];
          dp[i]=max(dp[i],buf);
      }
  }
  cout<<dp[(1ll<<n)-1]<<"\n";
  return 0;
}