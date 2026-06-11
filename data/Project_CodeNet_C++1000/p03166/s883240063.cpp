#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int maxN = 1e5+5;
const int mod = 1e9+7;
vector<int> g[maxN];
int dp[maxN];

int dfs(int u){
    if(dp[u]!=-1)
        return dp[u];
    int temp = 0;
    for(auto x:g[u]){
        temp = max(temp,dfs(x)+1);
    }
    return dp[u] = temp;
}



void solve(){
    int n,m,u,v;
    cin>>n>>m;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<m;i++){
        cin>>u>>v,u--,v--;
        g[u].push_back(v);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,dfs(i));
    }
    cout<<ans<<endl;
}

int main()
{
    FASTIO
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}



