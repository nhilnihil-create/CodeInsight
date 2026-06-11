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
#define pb push_back5 5 3 2
#define F first
#define S second
#define mod 1000000007
#define init(a,x) memset(a,x,sizeof(a))

string x,y;
ll dp[3003][3003];

string  lcs(ll n , ll m)
{
	forA(i,0,n+1,1)dp[i][0]=0; forA(i,0,m+1,1)dp[0][i]=0;

	forA(i,1,n+1,1)
	{
		forA(j,1,m+1,1)
		{
			if(x[i-1]==y[j-1])dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}

	ll i=n,j=m; string s="";
	while(i>0 && j>0)
	{
		if(x[i-1]==y[j-1])
		{
			s=x[i-1]+s; i--;j--;
		}
		else
		{
			if(dp[i-1][j]>=dp[i][j-1])i--;
			else j--;
		}
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	//init(dp,-1);
	cin>>x; cin>>y; ll n,m ; n=x.size(); m=y.size();
	cout<<lcs(n,m);

	return 0;
}