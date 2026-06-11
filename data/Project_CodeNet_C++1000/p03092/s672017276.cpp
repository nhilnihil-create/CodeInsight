#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5005;
int n,A,B,dp[N][N*2],g[N][N*2],p[N],q[N];
signed main(){
	scanf("%lld%lld%lld",&n,&A,&B);
	for (int i=1;i<=n;i++)scanf("%lld",&p[i]);
	for (int i=1;i<=n;i++)q[p[i]]=i;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=2*n+1;j++){
			if (j%2==0)dp[i][j]=g[i-1][j-1];
			else dp[i][j]=g[i-1][j];
			if (j<q[i]*2)dp[i][j]+=B;
			else if (j>q[i]*2)dp[i][j]+=A;
			g[i][j]=min(dp[i][j],(j==1?1000000000000000000ll:g[i][j-1]));
		}
	printf("%lld\n",g[n][2*n+1]);
}