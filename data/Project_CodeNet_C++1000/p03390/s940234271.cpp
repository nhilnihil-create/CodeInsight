#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
int t;
LL x,y;
LL Sqrt(LL x) {
    LL l=0,r=1e9+1;
    while (l<r) {
	LL mid=(l+r+1)/2;
	if (mid*mid<=x) l=mid;
	else r=mid-1;
    }
    return l;
}
int main() {
    scanf("%d",&t);
    while (t--) {
	scanf("%lld%lld",&x,&y);
	LL sum=x*y-1;
	LL now=Sqrt(sum);
	LL ans=now+sum/(now+1)-1;
	if (x==y) ans++;
	printf("%lld\n",ans);
    }
    return 0;
}
