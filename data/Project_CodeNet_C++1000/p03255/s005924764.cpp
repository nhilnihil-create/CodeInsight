#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ll;

ll n, x, s, mn=1e18, a[200005];
int main() {
	int i, j, k;
	scanf("%lld%lld", &n, &x);
	for(i=1; i<=n; i++) scanf("%lld", &a[i]), a[i] += a[i-1];
	for(i=1; i<=n; i++) {
		s = (n+i) * x;
		for(j=n, k=5; j>0; j-=i) {
			s += k * (a[j] - a[max(j-i, 0)]);
			if(j<n) k += 2;
		}
		mn = min(mn, s);
	}
	printf("%lld", mn);
	return 0;
}