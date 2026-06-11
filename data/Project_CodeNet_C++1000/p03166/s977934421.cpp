#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define MAX 105
#define int long long int
using namespace std;

const int N = 100005;
vector<int> adj[N];
int dp[N];
bool visited[N];

void dfs(int v)
{
    visited[v] = true;
    for(auto it: adj[v])
    {
        if(!visited[it])
            dfs(it);
        dp[v] = max(dp[v], dp[it]+1);
    }
}
int32_t main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    
    memset(dp,0,sizeof(dp));
    memset(visited,false,sizeof(visited));
    
    for(int i = 1 ; i <= N ; i ++)
    {
        if(!visited[i])
            dfs(i);
    }
    
    int ans = 0;
    for(auto it: dp)
        ans = max(ans,it);
    cout << ans;
    return 0;
}
