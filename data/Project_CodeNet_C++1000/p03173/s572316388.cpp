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
     
     cin>>N;
     A.resize(N);
     for(auto &x:A) cin>>x;
     vector<vector<Int>> dp(N,vector<Int>(N,1e13)) ;
     for(int i=0;i<N;++i) dp[i][i]=0;
     
     vector<Int> pref(N);
     pref[0]=A[0];
     
     for(int i=1;i<N;++i){
         pref[i]=pref[i-1]+A[i];
     }
    
     for(int length=1;length<=N;++length){
         for(int i=0;i<N-length+1;++i){
             int j=i+length-1;
                for(int k=i;k<j;++k){
                    Int sum=pref[j]-(i ? pref[i-1]:0);
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum);
                }
         }
     }
     cout<<dp[0][N-1]<<"\n";
    
}
