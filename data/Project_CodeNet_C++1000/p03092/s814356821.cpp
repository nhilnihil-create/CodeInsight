#include<bits/stdc++.h>
using namespace std;
int n,a,b,p[5010];
long long dp[5010],Val;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n+1;++i){
		i<=n?scanf("%d",&p[i]):p[i]=n+1,dp[i]=1e18,Val=0;
		for(int j=i-1;j>=0;--j){
			if(p[j]<p[i])dp[i]=min(dp[i],dp[j]+Val);
			Val+=(p[j]>p[i]?a:b);
		}
	}
	printf("%lld",dp[n+1]);
	return 0;
}