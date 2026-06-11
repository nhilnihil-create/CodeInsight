//https://arc100.contest.atcoder.jp/tasks/arc100_c
//sos dp维护子集里面的最大的两个值  
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e6;
ll dp[N+100][2],a[N+100];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<(1<<n);i++) cin>>a[i];
	
	for(int i=0;i<1<<n;i++)
	{
		dp[i][0]=a[i];
		dp[i][1]=-0x3f3f3f3f3f3f3f3f;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=(1<<n)-1;j>=0;j--)
		{
			if(j>>i&1)//维护子集里面最大的两个值 
			{
				dp[j][1]=max(dp[j][1],dp[j^(1<<i)][0]);
				if(dp[j][0]<dp[j][1]) swap(dp[j][0],dp[j][1]);
				dp[j][1]=max(dp[j][1],dp[j^(1<<i)][1]);
			}
		}
	}
	ll ans=0;
	for(int i=1;i<1<<n;i++)
	{
		ans=max(ans,dp[i][0]+dp[i][1]);
		cout<<ans<<endl;
	} 
	return 0;
} 