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

LL n,a[20][20],dp[70000],val[70000];

int main()
{
	cin>>n;
	rep(i,n) rep(j,n) cin>>a[i][j];
	rep(i,1<<n)
	{
		rep(j,n)
		{
			if((i&(1<<j))==0) continue;
			for(int k=j+1;k<n;k++)
			{
				if((i&(1<<k))==0) continue;
				val[i]+=a[j][k];
			}
		}
	}
	rep(i,69995) dp[i]=-1e18;
	dp[0]=0;
	rep(i,1<<n)
	{
		int mask=((1<<n)-1)^i;
		for(int k=mask;k>0;k=(k-1)&mask) dp[i|k]=max(dp[i|k],dp[i]+val[k]);
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}