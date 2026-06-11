#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n, d;
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
	ll i, j, c;
	cin >> n;
	printf("1\n");
	for (i = d = c = 1; c < n; i += d, c++) {
		if ((i + d) * f(i + d * 2) > (i + d * 2) * f(i + d)) {
			d *= 10;
		}
		printf("%lld\n", i + d);
	}
    return 0;
}
