#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h[200005],a[200005],dp[200005];
int n;
void go(ll i, ll v)
{
	while(i<200005)
	{
		dp[i]=max(dp[i],v);
		i+=i&-i;
	}
}
ll query(int i)
{
	ll ans=0;
	while(i)
	{
		ans=max(ans,dp[i]);
		i-=i&-i;
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>h[i];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
		go(h[i],query(h[i])+a[i]);
	cout<<query(n);
	return 0;
}