#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

void dfs(vector<int> g[],int i,int vis[],stack<int> &s)
{
	vis[i] = 1;
	for(auto it : g[i])
	{
		if(vis[it])
			continue;
		dfs(g,it,vis,s);
	}
	s.push(i);
}


int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> g[n];
	int i;
	for(i = 0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		g[x].pb(y);
	}
	int vis[n]={0};
	stack<int> s;
	for(i=0;i<n;i++)
	{
		if(vis[i])
			continue;
		dfs(g,i,vis,s);
	}
	vector<int> v;
	while(!s.empty())
	{
		v.pb(s.top());
		s.pop();
	}
	int ans[n] = {0};
	int maxs = 0;
	for(i=n-1;i>=0;i--)
	{	
		ans[v[i]] = 0;
		for(auto it : g[v[i]])
		{
			ans[v[i]] = max(ans[v[i]],1+ans[it]);
		}
		maxs = max(maxs,ans[v[i]]);
	}
	cout<<maxs;
	return 0;

}
