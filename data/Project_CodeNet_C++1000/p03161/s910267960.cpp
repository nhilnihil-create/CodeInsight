#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int n,k,h[100001];
	int i,j,x,dp[100001];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++) scanf("%d",&h[i]);
	for(i=0;i<=n;i++) dp[i]=1000000000;
	dp[0]=0; x=0;
	for(i=0;i<n-1;i++){
		for(j=1;j<=k;j++){
			x=h[i]-h[i+j];
			if(x<0) x=-x;
			if(i+j<n&&dp[i+j]>x+dp[i]){
			dp[i+j]=x+dp[i];
			}
		}
	}
	printf("%d\n",dp[n-1]);
	return 0;
}