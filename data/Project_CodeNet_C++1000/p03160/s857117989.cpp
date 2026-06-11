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



int solve(int n)
{
	
	dp[0]=dp[1]=0;
	dp[2]=abs(a[1]-a[2]);
	for(int i=3;i<=n;++i)
	{
		dp[i]=min(abs(a[i]-a[i-1])+dp[i-1],abs(a[i]-a[i-2])+dp[i-2]);

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
				for(int i=1;i<=n;++i)
				{
					cin>>a[i];
				}
				cout<<solve(n)<<endl;

	return 0;
}
