#include<iostream>
using namespace std;
#define ll long long
ll n,a[407],pre[407],dp[407][407];

int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			int k=i+j;
			dp[j][k]=1e18;
			for(int p=j;p<=i+j;p++){
				dp[j][k]=min(dp[j][k],dp[j][p]+dp[p+1][k]+pre[k]-pre[j-1]);
			}
		}
	}
	printf("%lld\n",dp[1][n]);
}
