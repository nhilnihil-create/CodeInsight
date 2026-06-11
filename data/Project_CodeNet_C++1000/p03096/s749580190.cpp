/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,a[200010],dp[200010],lstc[200010],lst[200010];

int main()
{
	cin>>n;
	rep(i,n) cin>>a[i];
	rep(i,200005) lstc[i]=-1;
	rep(i,n)
	{
		if(lstc[a[i]]==-1)
		{
			lstc[a[i]]=i;
			lst[i]=-1;
		}
		else
		{
			lst[i]=lstc[a[i]];
			lstc[a[i]]=i;
		}
	}
	dp[0]=1;
	repn(i,n-1)
	{
		int pos=lst[i];
		if(pos==-1||pos==i-1) dp[i]=dp[i-1];
		else dp[i]=(dp[i-1]+dp[pos])%MOD;
	}
	cout<<dp[n-1]<<endl;
	return 0;
}