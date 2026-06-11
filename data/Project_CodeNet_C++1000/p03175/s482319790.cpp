#include<bits/stdc++.h>
#define size 100000
#define mod 1000000007
#define ll long long 
#define pb push_back
using namespace std;
vector<vector<int>> v(size+1);
ll dp[size+1][2];
bool vis[size+1][2];
ll solve(int src,int col,int par)
{
	if(dp[src][col]!=-1)
		return dp[src][col];
	ll ans=0;
    ll left=1;
	for(auto it=v[src].begin();it!=v[src].end();it++)
	{
		auto nbr=*it;
		if(nbr!=par)
            left=(left%mod*solve(nbr,0,src)%mod)%mod;	
	}
    ans=(ans+left)%mod;
    if(col==0){
        ll right=1;
	    for(auto it=v[src].begin();it!=v[src].end();it++)
	    {
		    auto nbr=*it;
		    if(nbr!=par)
		    {
			    right=(right*solve(nbr,1,src))%mod;
	    	}	
	    }
        
    ans=(ans+right)%mod;

    }
	return dp[src][col]=ans;
}
int main()
{
	int n;
	cin>>n;
	int degree[n+1]={};
	memset(dp,-1,sizeof(dp));
	memset(vis,false,sizeof(vis));
	
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
		degree[x]++;
		degree[y]++;
	}
	
	cout<<solve(1,0,-1)%mod<<"\n";
    
	return 0;
}