#include<bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<int>edges[n+1];
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        edges[u].push_back(v);
    }
    int dp[n+1]={0};
    memset(dp,-1,sizeof(dp));
    function<void(int)> dfs=[&](int s){
        dp[s]=0;
        for(auto x:edges[s]){
            if(dp[x]==-1)   dfs(x);
            dp[s]=max(dp[s],1+dp[x]);
        }
    };

    for(int i=1;i<=n;i++){
        if(dp[i]==-1)   dfs(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
}