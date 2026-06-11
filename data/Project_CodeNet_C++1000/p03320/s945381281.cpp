#include <iostream>
#include <cstdio>
#define N 1000005
using namespace std;

typedef long long ll;
ll n, d, z[N];
ll f(ll p) {
	ll s = 0;
	while (p > 0) {
		s += p % 10;
		p /= 10;
	}
	return s;
}
int main()
{
	ll i, j, t;
	cin >> n;
	printf("1\n");
	ll c;
	for (i = d = 1, c = 1; c < n; i += d, c++) {
		if ((i + d) * f(i + d * 2) > (i + d * 2) * f(i + d)) {
			d *= 10;
		}
		printf("%lld\n", i + d);
	}
    return 0;
}
