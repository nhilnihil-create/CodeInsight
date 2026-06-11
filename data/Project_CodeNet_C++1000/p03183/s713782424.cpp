#include<cstdio>
#include<algorithm>
#define int long long
const int N=1003,S=20003;
struct block{int w,s,v;}a[N];
inline bool Cmp(const block&a,const block&b){return a.s+a.w<b.s+b.w;}
int dp[N][S],n,ans;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i].w,&a[i].s,&a[i].v);
	std::sort(a+1,a+1+n,Cmp);
	for(int i=1;i<=n;i++)
	  for(int j=0;j<S;j++){
		dp[i][j]=dp[i-1][j];
		if(j>=a[i].w&&a[i].s>=j-a[i].w)
		  dp[i][j]=std::max(dp[i][j],dp[i-1][j-a[i].w]+a[i].v);
		if(i==n)ans=std::max(ans,dp[i][j]);
	  }
	printf("%lld",ans);
	return 0;
}