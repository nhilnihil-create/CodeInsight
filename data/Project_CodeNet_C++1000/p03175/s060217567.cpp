#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

int main()
{
	int n;
	cin>>n;
	int i;
	vector<int> g[n];
	for(i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	queue<int> q;
	int parent[n];
	int visited[n]={0};
	parent[0] = 0;
	q.push(0);
	visited[0] = 1;
	vector<int> order;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(auto it : g[x])
		{
			if(visited[it])
				continue;
			visited[it] = 1;
			parent[it] = x;
			q.push(it);
		}
		order.pb(x);
	}

	ll dp[n][2] = {0};
	for(i=n-1;i>=0;i--)
	{
		int v = order[i];
//		cout<<"V = "<<v<<"\n";
		dp[v][0] = dp[v][1] = 1;
		for(auto it : g[v])
		{
			if(it==parent[v])
				continue;
			dp[v][0] *= (dp[it][0]+dp[it][1])%M;
			dp[v][0] %= M;
			dp[v][1] *= (dp[it][0]);
			dp[v][1] %= M;
		}

		// if(dp[v][0] == 0)
		// 	dp[v][0] = 1;
		// if(dp[v][1]==0)
		// 	dp[v][1] = 1;
	}
	cout<<(dp[0][0]+dp[0][1])%M;

	return 0;

}
