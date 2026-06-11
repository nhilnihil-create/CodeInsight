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
double dp[3001][3001];
vector<double> v(1000000);
double fun(int i,int x)
{
	if(x==0)
	{
		return 1;
	}
	if(i==0)
	{
		return 0;
	}
	if(dp[i][x]>-0.9)
	{
		return dp[i][x];
	}
	//cout<<v[i]<<endl;
	dp[i][x]=((v[i]*fun(i-1,x-1)*1.0)+((1.0-v[i])*fun(i-1,x)*1.0)*1.0);
	return dp[i][x];
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	double x=fun(n,(n/2)+1);
	cout<<fixed<<setprecision(10)<<x<<endl;
	return ;	
}
signed main()
{
	for(int i=0;i<3001;i++)
	{
		for(int j=0;j<3001;j++)
		{
			dp[i][j]=-1.0;
		}
	}
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
    	//cout<<"Case #"<<i<<": ";
    	solve();
    	//cout<<endl;
    }
    return 0;
}