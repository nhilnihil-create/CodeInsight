#include <bits/stdc++.h>
using namespace std;

vector<int> vec[100006];
int dp[100006];


int rec(int src)
{
	if(dp[src]!=  -1) return dp[src];
	
	bool leaf = true;
	int bestchild = 0;
	
	for( auto x:vec[src])
	{
		leaf = false;
		bestchild = max(bestchild,rec(x));
	}
	
	return dp[src] = leaf?0:bestchild+1;
}

void solve()
{
	int v,e;
	cin>>v>>e;
	for(int i = 0;i<e;i++)
	{
		int src,dest;
		cin>>src>>dest;
		vec[src].push_back(dest);
	}
	memset(dp,-1,sizeof(dp));
	int ans = 0;
	for(int i  = 1;i<=v;i++)
	{
		ans = max(ans,rec(i));
	}
	cout<<ans;
	
	
	
	
}



int main()
{
	solve();
}




