#include <bits/stdc++.h>
using namespace std;

const long long inf = 2000000000000000000;

int t;
long long a, b, c, d, e, g, l, r, m;

signed main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (b > a || b > d || c < a % b)
			printf("No\n");
		else if (c >= b || b == d)
			printf("Yes\n");
		else {
			g = __gcd(b, d);
			l = -inf / g, r = inf / g;
			while (r - l > 1) {
				m = (l + r) / 2;
				if (m * g + (a % g) >= c - b + 1)
					r = m;
				else
					l = m;
			}
			if (l * g + (a % g) >= c - b + 1) 
				e = l;
			else
				e = r;
			if (e >= 0)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
}
