#include<bits/stdc++.h>
using namespace std;
#define chmax(a,b) if(a<b)a=b
#define LL long long
const int N=18;

int n;
LL a[N][N];
LL cost[1<<N],dp[1<<N];

int main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		scanf("%lld",&a[i][j]);
	for(int mask=1;mask<(1<<n);mask++)
	for(int i=0;i<n;i++) if(mask>>i&1)
	for(int j=i;j<n;j++) if(mask>>j&1)
		cost[mask]+=a[i][j];
	for(int mask=0;mask<(1<<n);mask++)
	for(int mask2=mask;mask2;mask2=(mask2-1)&mask)
		chmax(dp[mask],cost[mask2]+dp[mask-mask2]);
	printf("%lld\n",dp[(1<<n)-1]);
	
	return 0;
}