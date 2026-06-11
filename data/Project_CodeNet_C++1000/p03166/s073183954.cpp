#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define debug(x) cout<<x<<endl;
#define int ll
const ll INF = 1e18;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;

int dp[100001];
vector<vector<int> > v;

int dfs(int u)
{
	if(dp[u]!=-1)
		return dp[u];

	int c = 0;
	for(int i=0;i<v[u].size();i++)
		c = max(c, dfs(v[u][i]));

	return dp[u] = c+1;
}
 
int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);

	for(int i=0;i<100001;i++)
		dp[i] = -1;
 
 	int n,m;
 	cin>>n>>m;
 	v.resize(n);
 	for(int i=0;i<m;i++)
 	{
 		int a,b;
 		cin>>a>>b;
 		a--; b--;
 		v[a].push_back(b);
 	}


 	int ans = 0;
 	for(int i=0;i<n;i++)
 		ans = max(ans, dfs(i));

 	cout<<ans-1<<endl;
 
	return 0;
}