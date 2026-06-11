#include<bits/stdc++.h>
using namespace std;
long long a,b,ans;
int test;
inline bool check(long long o) {
	if (o&1) {
		long long x=(o+1)>>1,y=(o+1)>>1;
		if (a<=x) x++;
		if (b<=y) y++;
		return x*y<a*b;
	}
	else {
		long long x=o>>1,y=o>>1;
		y++;
		if (a<=x) x++;
		if (b<=y) y++;
		if (x*y>=a*b) return false;
		x=o>>1,y=o>>1;
		x++;
		if (a<=x) x++;
		if (b<=y) y++;
		return x*y<a*b;
	}
}

int main() {
	scanf("%d",&test);
	while (test--) {
		scanf("%lld%lld",&a,&b);
		long long l=0,r=2*((long long ) sqrt(a*b)+5);
		ans=0;
		while (l<=r) {
			long long mid=(l+r)>>1;
			if (check(mid)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%I64d\n",ans);
	}
}