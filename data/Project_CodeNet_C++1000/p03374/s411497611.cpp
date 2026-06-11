#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;
long long n, c, t, mx, x[N], v[N], a[N], b[N], ma[N], mb[N];
int main() {
	int i;
	scanf("%lld%lld", &n, &c);
	for(i=1; i<=n; i++) scanf("%lld%lld", &x[i], &v[i]);
	for(i=1, t=0; i<=n; i++) {
		t += v[i];
		a[i] = t - x[i];
		ma[i] = max(ma[i-1], a[i]);
	}
	for(i=n, t=0; i; i--) {
		t += v[i];
		b[i] = t - (c-x[i]);
		mb[i] = max(mb[i+1], b[i]);
	}
	mx = max(ma[n], mb[1]);
	for(i=1; i<n; i++) mx = max(mx, a[i] - x[i] + mb[i+1]);
	for(i=n; i>1; i--) mx = max(mx, b[i] - (c-x[i]) + ma[i-1]);
	cout<<mx;
	return 0;
}