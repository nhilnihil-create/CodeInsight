#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long 
ll dp[5050],A,B;
int a[5050],n;
int main(){
	memset(dp,63,sizeof dp);
	scanf("%d",&n);
	scanf("%lld%lld",&A,&B);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[n+1]=n+1;
	dp[0]=0;
	for (int i=1;i<=n+1;i++){
		int g=0;
		for (int j=i-1;j>=0;j--)
			if (a[j]>a[i])g++;
			else dp[i]=std::min(dp[i],dp[j]+A*g+B*(i-j-1-g));
	}
	printf("%lld",dp[n+1]);
} 