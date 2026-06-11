#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long
#define pb push_back
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf 1e18
#define pre(x,y) fixed<<setprecision(y)<<x
#define pq priority_queue<int>
#define mpq priority_queue<int,vector<int>,greater<int>>
#define gcd(x,y) __gcd(x,y)
#define mp make_pair

int dfs(vector<int> v[],vector<vector<int>> &dp,int src,int p,int b)
{

	if(dp[src][b]!=-1) return dp[src][b];
	int w1=1;
	int w2=1;
	int ans=0;
	for(auto x:v[src])
	{
		if(x!=p)
		{
			
			w1=(w1*dfs(v,dp,x,src,0))%mod;
			if(!b)
			{
				w2=(w2*dfs(v,dp,x,src,1))%mod;
			}
		}
	}
	ans=(ans+w1)%mod;
	if(!b) ans=(ans+w2)%mod;
	return dp[src][b]=ans;
}





int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,j,k;
    cin>>n;
    vector<int> v[n];
    int x,y;
    for(i=1;i<n;i++)
    {
    	cin>>x>>y;
    	x--;y--;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    vector<vector<int>> dp(n,vector<int>(2));
    for(i=0;i<n;i++)
    {
    	dp[i][0]=-1;
    	dp[i][1]=-1;
    }
    cout<<dfs(v,dp,0,0,0)<<endl;
	return 0;
}
