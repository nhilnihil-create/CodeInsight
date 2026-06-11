#include <cstdio>
long long n, k, s, mx, x, a[100005], b[100005];
int main() {
	int i, j;
	scanf("%lld%lld", &n, &k);
	for(i=0; i<n; i++) scanf("%lld%lld", a+i, b+i);
	k++;
	for(i=30; i>=0; i--) {
		if(k>>i & 1) {
			x ^= 1<<i;
			for(j=s=0; j<n; j++) {
				if(!(a[j]&x)) s += b[j];
			}
			if(s>mx) mx = s;
		}
		x ^= 1<<i;
	}
	printf("%lld", mx);
	return 0;
}