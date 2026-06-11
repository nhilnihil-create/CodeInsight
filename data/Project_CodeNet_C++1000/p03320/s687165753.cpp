#include <cstdio>
typedef long long ll;
ll k, n=1, d=1;

ll f(ll p) {
	ll s=0;
	for(; p; p/=10) s += p%10;
	return s;
}

int main() {
	scanf("%lld", &k);
	puts("1");
	while(--k) {
		if((n+d*10) * f(n+d) < (n+d) * f(n+d*10)) d*=10;
		printf("%lld\n", n+=d);
	}
	return 0;
}