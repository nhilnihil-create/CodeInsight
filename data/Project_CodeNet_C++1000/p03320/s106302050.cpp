#include <bits/stdc++.h>

using namespace std;

int n;
long long cur, ba, bb;
long long ta, tb;

int sum(long long a) {
	int re = 0;
	while (a) {
		re += a % 10;
		a /= 10;
	}
	return re;
}

int main() {
	scanf("%d", &n);
	while (n--) {
		cur++;
		ba = cur;
		bb = sum(cur);
		ta = 10;
		while (cur * 10 >= ta) {
			cur = cur - cur % ta + ta - 1;
			tb = sum(cur);
			if (cur * bb < ba * tb) {
				ba = cur;
				bb = tb;
			}
			ta *= 10;
		}
		cur = ba;
		printf("%lld\n", cur);
	}
	return 0;
}
