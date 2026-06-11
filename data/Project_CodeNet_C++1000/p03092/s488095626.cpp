#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5010;
LL n, a, b, p[N], id[N], dp[N][N], s[N][N];
int main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	for(LL i=1; i<=n; ++i)scanf("%lld",&p[i]), id[p[i]]=i;
	memset(s,0x3f,sizeof(s));
	for(LL i=0; i<=n; ++i)s[0][i]=0;
	for(LL i=1; i<=n; ++i)
		for(LL j=0; j<=n; ++j){
			dp[i][j]=s[i-1][j]+(j>=id[i]?a:b);
			if(j==id[i])dp[i][j]=min(dp[i][j],s[i-1][j-1]);
			if(j>0)s[i][j]=min(s[i][j-1],dp[i][j]);else s[i][j]=dp[i][j];
		}
	LL mn=0x3f3f3f3f3f3f3f3f;
	for(LL i=1; i<=n; ++i)mn=min(mn,dp[n][i]);
	printf("%lld",mn);
	return 0;
}