#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5005;
int n,A,B,p[N];long long dp[N][N];
int main(){
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	memset(dp,63,sizeof(dp));
	for(int i=1;i<=n;++i){
		dp[i][i]=min(dp[i][i],1ll*(i-1)*A);
		for(int j=1;j<i;++j)
			if(p[j]<p[i]){
				dp[i][i]=min(dp[i][i],dp[i-1][j]);
				dp[i][j]=min(dp[i][j],dp[i-1][j]+A);
			}else{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+B);
			}
	}
	long long ans=dp[0][0];
	for(int i=1;i<=n;++i)ans=min(ans,dp[n][i]);
	printf("%lld\n",ans);
	return 0;
}
