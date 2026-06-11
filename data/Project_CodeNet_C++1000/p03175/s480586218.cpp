#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const ll MOD = 1e9 + 7;
const int MAX = 1e6+ 6;
vector<int>edg[MAX];
ll dp[MAX][2];

void dfs(int node, int p) {
    
    dp[node][0] = dp[node][1] = 1;
    
    int cnt = 0;
    for(auto x: edg[node]) {
        if( p == x) continue;
        cnt++;
    }
    if(cnt == 0) return ;
    
    
    for(auto x : edg[node]) {
        if(x == p) continue;
        dfs(x, node);
        dp[node][1] = (dp[node][1] * dp[x][0])%MOD;
        dp[node][0] = (dp[node][0] * (dp[x][0] + dp[x][1]) %MOD) %MOD;
    }
}


int main()
{
    fastRead;
    int n;
    cin>>n;
    for(int i =1 ;i < n ; i++ ) {
        int u, v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    dfs(1, -1);
    cout<<(dp[1][0] + dp[1][1])%MOD<<'\n';
    
}