#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define endl '\n'
#define N 200005
using namespace std;
vector<int>adj[N];
int dp[N],vis[N];
int  dfs (int s)
{
	int ans = 0;
	vis[s] = 1;
	for(int i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==0) 
		ans = max (ans, 1 + dfs(adj[s][i]));
		else 
		ans = max(ans,1+dp[adj[s][i]]);
	}
	return dp[s] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0,x,y;i<m;i++){
    	cin>>x>>y;
    	adj[x].pb(y);
    }
    
    int ans = 0;
    for(int i=1;i<=n;i++)
    ans = max(ans,dfs(i));
    cout<<ans<<endl;
}