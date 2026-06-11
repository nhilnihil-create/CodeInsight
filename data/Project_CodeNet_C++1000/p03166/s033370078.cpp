#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define vi vector <int>
#define endl "\n"
#define vvi vector <vector<int> >
#define vii vector <pair<int,int> >
#define rep(i,a,b) for (int i=a;i<b;i++)
#define repD(i,a,b) for (int i=a;i>=b;i--)
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define gcd __gcd
#define init(i,k) memset(i,k,sizeof i)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define setBits(x) __builtin_popcountll(x)
#define pii pair <int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define N 100005
vector<int>dp(N,-1);
vector<int> adj[N];
int dfs(int x)
{
	if(dp[x]!=-1)
	{
		return dp[x];
	}
	int len=0;
	for(int i=0;i<adj[x].size();i++)
	{
		int c=dfs(adj[x][i]);
		len=max(len,c);
	}
	len=len+1;
	dp[x]=len;
	return len;
}
int solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]==-1)
		{
			dp[i]=dfs(i);
		}
		//cout<<i<<" "<<dp[i]<<endl;
		ans=max(ans,dp[i]);
	}
	return ans-1;
}
signed main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
    	cout<<solve()<<endl;
    }
    return 0;
}