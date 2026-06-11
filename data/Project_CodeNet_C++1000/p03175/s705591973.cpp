#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int solve(int dp[][2],vector<int>* edges,int n,int x,int constraint,int parent){
    //base case is not necessary
    // if(edges[x].size()==1 && parent!=-1){
    //     if(constraint==0){
    //         return 2;
    //     }
    //     else{
    //         return 1;
    //     }
    // }
    if(dp[x][constraint]!=-1){
        return dp[x][constraint];
    }
    
    int ans=1;
    for(int i=0;i<edges[x].size();i++){
        if(edges[x][i]!=parent)
            ans=(ans*solve(dp,edges,n,edges[x][i],0,x))%mod;
    }
    if(constraint==0){
        int ans2=1;
        for(int i=0;i<edges[x].size();i++){
            if(edges[x][i]!=parent)
                ans2=(ans2*solve(dp,edges,n,edges[x][i],1,x))%mod;
        }
        ans=(ans+ans2)%mod;
    }
    return dp[x][constraint]=ans;
}
int32_t main(){
    int n;
    cin>>n;
    vector<int> edges[n];
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        edges[u-1].push_back(v-1);
        edges[v-1].push_back(u-1);
    }
    int dp[n][2];
    memset(dp,-1,sizeof dp);
    cout<<solve(dp,edges,n,0,0,-1)<<endl;
    return 0;
}