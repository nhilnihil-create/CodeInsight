#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=5e3+5;
int n,R,L,a[N];ll ans=1e18,dp[N];

int main() {
	scanf("%d%d%d",&n,&R,&L);
	memset(dp,64,sizeof(dp)),dp[0]=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) {
		for(int j=0;j<a[i];++j) dp[a[i]]=min(dp[a[i]],dp[j]);
		for(int j=0;j<a[i];++j) dp[j]+=R;
		for(int j=a[i];j<n;++j) dp[j+1]+=L;
	}
	for(int i=0;i<=n;++i) ans=min(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}