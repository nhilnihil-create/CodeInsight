#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[100001],n,m;
vector<vector<int>> g(100001,vector<int>());

int call(int u){
    if(dp[u]!=-1)
        return dp[u];
    int res=0;
   for(auto v:g[u]){
        res=max(res,1+call(v));
   }
   return dp[u]=res;
}


int main(){

    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    int ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        if(dp[i]==-1){
            ans=max(ans,call(i));
        }
    }
    cout<<ans;



return 0;
}
