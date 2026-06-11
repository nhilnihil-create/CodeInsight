#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define drp(i,st,ed) for (int i=st;i>=ed;--i)

typedef long long LL;
const int N=200005;

LL a[N],b[N];
LL x[N],v[N];
LL s1[N],s2[N],mx1[N],mx2[N];

int main(void) {
	int n; LL m; scanf("%d%lld",&n,&m);
	rep(i,1,n) scanf("%lld%lld",&x[i],&v[i]);
	rep(i,1,n) {
		s1[i]=s1[i-1]+v[i]-(x[i]-x[i-1]);
		mx1[i]=std:: max(mx1[i-1],s1[i]);
	}
	x[n+1]=m;
	drp(i,n,1) {
		s2[i]=s2[i+1]+v[i]-(x[i+1]-x[i]);
		mx2[i]=std:: max(mx2[i+1],s2[i]);
	}
	LL ans=0;
	ans=std:: max(ans,mx1[n]);
	ans=std:: max(ans,mx2[1]);
	rep(i,1,n) {
		ans=std:: max(ans,s1[i]-x[i]+mx2[i+1]);
		ans=std:: max(ans,s2[i]-(m-x[i])+mx1[i-1]);
	}
	printf("%lld\n", ans);
	return 0;
}