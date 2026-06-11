#include <bits/stdc++.h>
#define int long long int 
#define N 100001
using namespace std;
int DP[N][2];
bool vis[N];
vector<int> adj[N];
const int mod = 1e9 +7;
void dfs(int x)
{
    int w=1,b=1;
    vis[x]=1;
    for(auto i:adj[x])
    {
        if(!vis[i])
        {
            dfs(i);
            w = w*((DP[i][0] + DP[i][1])%mod)%mod;
            b = b*(( DP[i][1])%mod)%mod;
        }
        
    }
    DP[x][0] = (DP[x][0]*b)%mod;
    DP[x][1] = (DP[x][1]*w)%mod;
}

signed main() {
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        DP[i][0]=1;
        DP[i][1] =1;
        vis[0]=0;
    }
    dfs(1);
    cout<<(DP[1][0] + DP[1][1])%mod;
    return 0;
}