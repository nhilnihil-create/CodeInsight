#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX=1e5;
const int M=1e9+7;
vector<vector<ll>> dp(MAX,vector<ll>(2));
vector<vector<int>> adj(MAX);
void dfs(int u,int prev){
    dp[u][0]=1;
    dp[u][1]=1;
    for(int it:adj[u]){
        if(it!=prev){
            dfs(it,u);
          	dp[u][1]=dp[u][1]*((dp[it][1]+dp[it][0])%M)%M;
            dp[u][0]=(dp[u][0]*dp[it][1])%M;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0,-1);
    int res=(dp[0][0]+dp[0][1])%M;
    cout<<res<<'\n';
    return 0;
}