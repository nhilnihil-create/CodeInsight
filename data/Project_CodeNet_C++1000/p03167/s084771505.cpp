#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define vi vector <int>
#define endl "\n"
#define f(n) for(int i=0;i<n;i++)
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
#define mod 1000000007
int solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char>>v(n,vector<char>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>v[i][j];
		}
	}	
	vector<vector<int> > dp(n,vector<int> (m));
	dp[0][0]=1;
	for(int i=1;i<n;i++)
	{
		if(v[i][0]=='#')
		{
			dp[i][0]=0;
		}
		else
		{
			dp[i][0]=dp[i-1][0];
		}
	}
	for(int j=1;j<m;j++)
	{
		if(v[0][j]=='#')
		{
			dp[0][j]=0;
		}
		else
			dp[0][j]=dp[0][j-1];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(v[i][j]=='#')
			{
				dp[i][j]=0;
			}
			else
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
				dp[i][j]%=mod;
			}
		}
	}
	return dp[n-1][m-1];
}
signed main()
{
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
    	//cout<<"Case #"<<i<<": ";
    	cout<<solve()<<endl;
    	//cout<<endl;
    }
    return 0;
}