#include <bits/stdc++.h>
const int N=5005;
long long dp[N][N],ans=100000000000000;
int a[N],x,A,B,n; 
int main(){
	scanf("%d%d%d",&n,&A,&B);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]=i;
	}
	memset(dp,0x3f,sizeof(dp));
	for (int i=0;i<=n;i++) dp[0][i]=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++){
			if (a[i]<a[j])
				dp[i][a[j]]=std::min(dp[i][a[j]],dp[i-1][a[j]]+A);
			else dp[i][a[j]]=std::min(dp[i][a[j]],dp[i-1][a[j]]+B),
			dp[i][a[i]]=std::min(dp[i][a[i]],dp[i-1][a[j]]);
			
		}
	for (int i=1;i<=n;i++) ans=std::min(ans,dp[n][i]);
	printf("%lld\n",ans); 
} 