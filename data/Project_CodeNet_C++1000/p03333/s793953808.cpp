#include <cstdio>
#include <algorithm>
using namespace std;
long long n, ans, d, l[100005], r[1000005];
int main() {
	int i;
	scanf("%lld", &n);
	for(i=1; i<=n; i++) scanf("%lld%lld", l+i, r+i);
	sort(l, l+n+1);
	sort(r, r+n+1);
	for(i=0; ; i++) {
		d = l[n-i] - r[i];
		if(d>0) ans += d; else break;
	}
	printf("%lld", ans*2);
	return 0;
}