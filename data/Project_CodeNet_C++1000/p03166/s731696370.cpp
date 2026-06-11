/*input

*/

#include<bits/stdc++.h>
using namespace std;
//#define int 					ll
#define ios	    				ios_base::sync_with_stdio(false); cin.tie(0)

// Data Structures //
#define ll 						long long
#define vi          			vector<ll>

// Functions //
#define pb 						push_back

int visited[100005];
ll dp[100005];
vi v[100005];

void visit(ll node)
{
	dp[node] = 0;
	visited[node] = 1;
	for(ll child : v[node] )
	{
		if(visited[child]==0) visit(child);
		dp[node] = max(dp[node],1+dp[child]);
	}
	
	return;		
}



void solve()
{
	ll n,m,x,y,k=0,t,cnt=0;
	cin>>n>>m;
	for(int i=0;i<m;i++) 
	{
		cin>>x>>y;
		v[x].pb(y);
	}
	
	for(ll i=1;i<=n;i++) 
	{
		if(visited[i]==0) 
		{
			visit(i);
		}
	}
	
	for(int i=1;i<=n;i++)	
	{
		cnt = max(cnt,dp[i]);
	}

	
	cout<<cnt<<endl;
}


signed main()
{
	ios;
	ll tests=1;
	memset(visited,0,sizeof(visited));
	//cin>>tests;
	while(tests--)
	{
		solve();
	}
	return 0;
}
