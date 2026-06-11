#include <bits/stdc++.h>
using namespace std;

#define ll long long int
 
ll dp[100005];
bool visited[100005];
vector<ll> edge[100005]; 

void visit(ll vertex)
{
	if(!visited[vertex])
	{
		visited[vertex] = 1;
		dp[vertex] = 0;
		for(auto child : edge[vertex] )
		{
			if(!visited[child] ) visit(child);
			dp[vertex] = max(dp[vertex], 1+dp[child]);
		}
	}	
	return;
}

int main()
{
	ll m,n,x,y,mx = -1;
	cin>>n>>m;
	
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y;
		edge[x].push_back(y);
	}
	
	for(ll i=1;i<=n;i++)
	{
		if(!visited[i]) 
		{
			visit(i);
		}
	}
	
	for(ll i=1;i<=n;i++)
	{
		mx = max(mx,dp[i]);
	}
	cout<<mx<<endl;
	
	return 0;
}
