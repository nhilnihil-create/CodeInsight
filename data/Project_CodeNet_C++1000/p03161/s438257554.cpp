#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

using namespace std;
int a[100005];
int dp[100005];


int _gcd(int a,int b)
{
	return (b==0?a:_gcd(b,a%b));
}
bool cmp(int a,int b)
{
	return a>b;
}



int solve(ll n,ll k)
{
	
	dp[0]=dp[1]=0;
	dp[2]=abs(a[1]-a[2]);
	for(int i=3;i<=n;++i)
	{
		dp[i]=INT_MAX;
		for(int j=i-1;j>=1 && (i-j)<=k;--j)
		{
			dp[i]=min(dp[i],abs(a[i]-a[j])+dp[j]);
		}
	}
	return dp[n];


}

int main()
{
	fast;
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
				ll n;
				cin>>n;
				ll k;
				cin>>k;
				for(int i=1;i<=n;++i)
				{
					cin>>a[i];
				}
				cout<<solve(n,k)<<endl;

	return 0;
}
