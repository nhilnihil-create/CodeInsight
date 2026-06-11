#include <bits/stdc++.h>
using namespace std;
#define F(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
#define mod 1000000007
void dfs(vvi &v, vi &dp, vi &vis, int n,int i){
	vis[i]=1;
	F(j,0,v[i].size()){
		if(!vis[v[i][j]])dfs(v,dp,vis,n,v[i][j]);
	dp[i]=max(dp[i],dp[v[i][j]]+1);
}
}
int main()
{	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int w=1;
	// cin>>w;
	while(w--){
		int n,m;
		cin>>n>>m;
		vvi v(n);
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x-1].pb(y-1);
		}
		vi dp(n,0),vis(n,0);
		F(i,0,n){
			if(!vis[i])
			dfs(v,dp,vis,n,i);
		}

		int ma=0;
		F(i,0,n){
			ma=max(dp[i],ma);
		}
		cout<<ma;

	}
}