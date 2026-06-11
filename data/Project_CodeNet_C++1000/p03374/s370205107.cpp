#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int n, v[N];
LL x[N], c;
LL dp[N][2],pre[N],suf[N];
void solve() {
	for(int i=1; i<=n; i++) {
		pre[i]=pre[i-1]+v[i];
		dp[i][0]=max(dp[i-1][0], pre[i]-x[i]);
		//cout << i << " 0 " << dp[i][0] << endl; 
	}
	for(int i=n; i>=1; i--) {
		suf[i]=suf[i+1]+v[i];
		dp[i][1]=max(dp[i+1][1], suf[i]-(c-x[i]));
	}
	LL ans = max({0LL,dp[n][0],dp[1][1]});
	for(int i=1; i<=n; i++) {
		ans=max(ans, dp[i][0]+suf[i+1]-2*(c-x[i+1]));
	}
	for(int i=n; i>=1; i--) {
		ans=max(ans, dp[i][1]+pre[i-1]-2*x[i-1]);
	}
	printf("%lld\n",ans);
}
int main() {
	scanf("%d%lld",&n,&c);
	for(int i=1; i<=n; i++) {
		scanf("%lld%d",&x[i],&v[i]);
	}
	solve();
	return 0;
}