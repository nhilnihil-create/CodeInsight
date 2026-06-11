#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define forA(i,a,n,x) for(auto i=a;i<n;i+=x)
#define forD(i,a,n,x) for(auto i=n-1;i>=0;i-=x)
#define ranit(it,n) for(auto it:n)
#define testCases ll t;cin>>t;while(t--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define init(a,x) memset(a,x,sizeof(a))

ll n,m; ll dp[1003][1003]; char grid[1003][1003];

bool isvalid(ll i , ll j)
{
	if(i<0 || i>=n || j<0 || j>=m)return false;
	else
	{
		if(grid[i][j]=='#')return false; else return true;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin>>n>>m;
	init(dp,0);

	forA(i,0,n,1)forA(j,0,m,1)cin>>grid[i][j];
	ll r=0,c=0;
	forA(i,0,n,1){if(grid[i][0]=='.')dp[i][0]=1; else break;}
	forA(i,0,m,1){if(grid[0][i]=='.')dp[0][i]=1; else break;}

	forA(i,1,n,1)
	{
		forA(j,1,m,1)
		{
			if(grid[i][j]=='.')dp[i][j]=((dp[i-1][j]%mod)+(dp[i][j-1]%mod))%mod;
		}
	}

	//forA(i,0,n,1){forA(j,0,m,1)cout<<dp[i][j]<<" "; cout<<"\n";}

	cout<<dp[n-1][m-1];
	return 0;
}