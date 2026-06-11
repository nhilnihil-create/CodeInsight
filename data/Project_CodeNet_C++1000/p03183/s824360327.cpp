#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int dp[1005][20005];
tuple<int,int,int> arr[1005];
bool cmp(tuple<int,int,int>a,tuple<int,int,int>b)
{
	return get<0>(a)+get<1>(a)<get<0>(b)+get<1>(b);
}
signed main()
{
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		int w,s,v;
		cin>>w>>s>>v;
		arr[i]=make_tuple(w,s,v);
	}
	sort(arr+1,arr+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		int w,s,v;
		tie(w,s,v)=arr[i];
		for(j=1;j<=20000;j++)
		{
			dp[i][j]=/*max*/(dp[i-1][j]/*,dp[i][j-1]*/);
			if(s>=j-w&&j>=w)
			{
			dp[i][j]=max(dp[i-1][j-w]+v,dp[i][j]);
		}
		}
	}
	int x=0;
	for(i=1;i<=20000;i++)
	if(x<dp[n][i])
	x=dp[n][i];
	cout<<x<<"\n";
	/*cout<<dp[n][20000]<<"\n";*/
}