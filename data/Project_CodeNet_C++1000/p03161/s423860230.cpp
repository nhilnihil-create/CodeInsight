#include<bits/stdc++.h>
#define f(i,n) for(ll i=0;i<n;i++)
#define fe(i,a,b) for(ll i=a;i<=b;i++)
#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
using namespace std;
ll dp[100005];
ll mincost(vector<int>&a, ll n, ll k)
{
	if(dp[n]!=-1)
		return dp[n];
	if(n==1)
		return dp[n]=0;
	if(n<1)
		return INT_MAX;
	dp[n]=INT_MAX;
	for(int i=1;i<=k;i++)
	{
		if(n-i<=0)
			break;
		dp[n]=min(abs(a[n-i-1]-a[n-1])+mincost(a,n-i,k),dp[n]);
	}
	return dp[n];
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	ll n, k;
	cin>>n>>k;
	vector<int>a(n);
	f(i,n)
		cin>>a[i];
	cout<<mincost(a,n,k)<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--)
		solve();
    return 0;
}
