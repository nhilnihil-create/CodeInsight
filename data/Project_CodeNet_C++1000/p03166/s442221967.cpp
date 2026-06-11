#include <bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

const int MAXN=500005;
const long MOD=(long)(1e9+7);
vector<int> adj[MAXN];
vector<pair<int,int>> G[MAXN];

Int N,M,K;
Int B,C,H,W;
Int X,Y,Z;
vector<Int> A;

Int ceilS(Int x,Int y){
    return (x+y-1)/y;
}
using D=long double;

Int perform(Int x){
    return (x*(x+1))/2LL;
}
vector<Int> dp;
bool VIS[MAXN];

void dfs(int u){
    VIS[u]=true;
        for(auto &v:adj[u]){
            if(!VIS[v])
                dfs(v);
            dp[u]=max(dp[u],1+dp[v]);
        }
}

int main()
{
     cin>>N>>M;
     for(int i=0;i<M;++i){
         int u,v;
         cin>>u>>v;
         u--;v--;
         adj[u].pb(v);
     }
     memset(VIS,0,sizeof(VIS));
     dp.resize(N);
     fill(dp.begin(),dp.end(),0);
     for(int i=0;i<N;++i){
         if(VIS[i]) continue;
         dfs(i);
     }
     Int ans=0;
     for(int i=0;i<N;++i){
         ans=max(ans,dp[i]);
     }
     cout<<ans<<'\n';
}
