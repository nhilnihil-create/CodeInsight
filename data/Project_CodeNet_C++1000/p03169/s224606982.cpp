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
double dp[301][301][301];
double fun(int x,int y,int z,int n)
{
	if(x<0 || y<0 || z<0)
	{
		return 0;
	}
	if(x==0 && y==0 && z==0)
	{
		return 0;
	}
	if(dp[x][y][z]>-0.9)
	{
		return dp[x][y][z];
	}
	double lol=x*1.0*fun(x-1,y,z,n)+y*1.0*fun(x+1,y-1,z,n)+z*1.0*fun(x,y+1,z-1,n)+n;
	lol=lol/((x+y+z)*1.0);
	dp[x][y][z]=lol;
	return lol;
}
void solve()
{
	int n;
	cin>>n;
	vi v(n);
	f(n)
		cin>>v[i];
	int x=0,y=0,z=0;
	f(n)
	{
		if(v[i]==1)
		{
			x++;
		}
		if(v[i]==2)
		{
			y++;
		}
		if(v[i]==3)
		{
			z++;
		}
	}
	cout<<fixed<<setprecision(10)<<fun(x,y,z,n)<<endl;;
}
signed main()
{
    int t=1;
    //cin>>t;
    for(int i=0;i<301;i++)
    {
    	for(int j=0;j<301;j++)
    	{
    		for(int k=0;k<301;k++)
    		{
    			dp[i][j][k]=-1.0;
    		}
    	}
    }
    for(int i=1;i<=t;i++)
    {
    	//cout<<"Case #"<<i<<": ";
    	solve();
    	//cout<<endl;
    }
    return 0;
}