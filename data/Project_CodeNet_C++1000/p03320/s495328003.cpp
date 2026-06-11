#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k; ll now = 1;
int dig(ll x) {
	return x ? dig(x / 10) + x % 10 : 0;
}
int main() {
	scanf("%d", &k);
	while (k--) {
		printf("%lld\n", now);
		ll tmp = 1;
		while (dig(now + tmp * 10) * (now + tmp) > dig(now + tmp) * (now + tmp * 10)) tmp *= 10;
		now += tmp;
	}
}
