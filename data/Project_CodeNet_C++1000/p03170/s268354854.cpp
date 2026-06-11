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
     
     cin>>N>>K;
     A.resize(N);
     
     for(auto &x:A) cin>>x;
     
     vector<bool> dp(K+1,false);
     dp[0]=0;
     
        for(int i=1;i<K+1;++i){
            for(int j=0;j<N;++j){
                if(i<A[j]) continue;
                if(!dp[i-A[j]]){
                    dp[i]=true;
                    break;
                }
            }
        }
        cout<<(dp[K]==true ? "First\n":"Second\n");
}
