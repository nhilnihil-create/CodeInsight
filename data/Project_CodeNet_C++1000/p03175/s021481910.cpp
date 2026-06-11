#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int n;
vector<vector<int>>adj;
vector<int>dp1,dp2;
void dfs(int i,int par)
{
    dp1[i]=dp2[i]=1;
    for(int c:adj[i]){
        if(c==par)continue;
        dfs(c,i);
        dp2[i]=(dp2[i]*(dp2[c]+dp1[c])%mod)%mod;
    }
    for(int c:adj[i]){
        if (c!=par)dp1[i]=(dp1[i]*dp2[c])%mod;
    }
}
int32_t main()
{
    cin>>n;adj.resize(n+1);dp1.resize(n+1);dp2.resize(n+1);
    for(int i = 0;i<n-1;i++){int a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);}
    dfs(1,1);
    cout<<((dp1[1]+dp2[1])%mod+mod)%mod;
    return 0;
}