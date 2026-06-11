#include<iostream>
#include<vector>
#define F first
#define S second
#define MOD 1000000007
using namespace std;

vector<pair<long long,long long>>dp;

void dfs(int i, int par, vector<int>adj[] )
{
	dp[i]={1ll,1ll};//{w,b}
	
	for(int x:adj[i])
	{
		if(x!=par)
		{
			dfs(x,i,adj);
			dp[i].F = ((dp[i].F*dp[x].F)%MOD + (dp[i].F*dp[x].S)%MOD)%MOD;
			dp[i].S = (dp[i].S*dp[x].F)%MOD;
		}
	}
	//cout<<i<<" "<<dp[i].F<<" "<<dp[i].S<<endl;
}

int main()
{
	int n;
	cin>>n;
	vector<int>v[n+1];
	
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x-1].push_back(y-1);
		v[y-1].push_back(x-1);
	}
	dp.assign(n,{0,0});
	
	dfs(0,-1,v);
	cout<<((dp[0].F+dp[0].S)%MOD);
	
	
	
	return 0;
}

