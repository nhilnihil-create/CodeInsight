#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)
#define allr(v) (v).rbegin(),(v).rend()
#define vrsort(v) sort(allr(v))
const ll inf=1LL<<60;

int main(){
  ll i=0,j,N,M;
  ll cost[10]={0,2,5,5,4,5,6,3,7,6};
  cin>>N>>M;
  vec use(M);
  rep(i,M){
    cin>>use[i];
  }
  map<ll,ll> dp;
  For(i,-10,N)dp[i]=-inf;
  dp[0]=0;
  rep(i,N){
    rep(j,M){
      dp[i+cost[use[j]]]=max(dp[i+cost[use[j]]],dp[i]+1);
    }
  }
  i=N;
  vrsort(use);
  while(i>0){
    rep(j,M){
      if(dp[i]-1==dp[i-cost[use[j]]]){
        cout<<use[j];
        i-=cost[use[j]];
        break;
      }
    }
  }
  cout<<endl;
  return 0;
}