#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL n,a[N];
int main(){
	scanf("%lld",&n);
	for(LL i=1; i<=n; ++i)scanf("%lld",&a[i]);
	for(LL i=1; i<=n; ++i)if(a[i]>i-1||a[i]-a[i-1]>1)return puts("-1"),0;
	LL ans=0;
	for(LL i=n; i>=1; --i)
		if(a[i]+1!=a[i+1])ans+=a[i];
	printf("%lld",ans);
	return 0;
}