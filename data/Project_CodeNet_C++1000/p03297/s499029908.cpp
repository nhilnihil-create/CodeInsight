#include <bits/stdc++.h>
using namespace std;

int t;
long long a, b, c, d, e, f, g;

signed main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (b > a || b > d)
			printf("No\n");
		else if (c >= b)
			printf("Yes\n");
		else {
			e = a % b;
			g = __gcd(b, d);
			f = ((c - e + g) / g) * g;
			if (c < e || f + e < b)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
}
