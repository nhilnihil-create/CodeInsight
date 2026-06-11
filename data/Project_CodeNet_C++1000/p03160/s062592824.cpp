#include<bits/stdc++.h>
#define f(i,n) for(ll i=0;i<n;i++)
#define fe(i,a,b) for(ll i=a;i<=b;i++)
#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
using namespace std;
ll dp[100005];
ll mincost(vector<int>&a, ll n)
{
	if(dp[n]!=-1)
		return dp[n];
	if(n==1)
		return dp[n]=0;
	if(n<1)
		return INT_MAX;
	dp[n]=min(abs(a[n-2]-a[n-1])+mincost(a,n-1),abs(a[n-3]-a[n-1])+mincost(a,n-2));
	return dp[n];
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	ll n;
	cin>>n;
	vector<int>a(n);
	f(i,n)
		cin>>a[i];
	cout<<mincost(a,n)<<endl;
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