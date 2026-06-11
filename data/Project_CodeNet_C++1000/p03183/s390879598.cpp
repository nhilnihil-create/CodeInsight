#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll,ll,ll,ll> T;
#define MAX 1e9
struct block { ll sum, w, s, v; };
bool comp(block a, block b) { return a.sum > b.sum; }
int main(){
  int N;cin>>N;
  block Block[N];
  rep(i,N){
    ll w,s,v,sum;
    cin>>w>>s>>v;
    sum=w+s;
    Block[i]=block{sum,w,s,v};
  }
  sort(Block, Block + N, comp);
  ll dp[N+1][20005];
  rep(i,N+1){rep(j,20001){dp[i][j]=0ll;}}
  for(int i = 0; i < N; i++) {
        for(int j = 0; j < 20001; j++) {
          dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
          ll W,S,V;
          W=Block[i].w;
          S=Block[i].s;
          V=Block[i].v;
          if(j-W<0){continue;}
          dp[i+1][min(S,j-W)]=max(dp[i+1][min(S,j-W)],dp[i][j]+V);
        }
    }
  ll ans=0ll;
  rep(i,20001){
  	ans=max(dp[N][i],ans);
  }
  cout<<ans;
  
}
