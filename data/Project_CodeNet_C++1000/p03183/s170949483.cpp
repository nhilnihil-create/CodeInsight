#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005,M=20005;
struct block
{
	int w,s,v;
	bool operator<(const block k)const
	{
		return w+s<k.w+k.s;
	}
}a[N];
int n,dp[M],ans;
main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].w>>a[i].s>>a[i].v;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=a[i].s;j>=0;j--)
			dp[j+a[i].w]=max(dp[j+a[i].w],dp[j]+a[i].v);
	for(int i=0;i<=20000;i++)
		ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}