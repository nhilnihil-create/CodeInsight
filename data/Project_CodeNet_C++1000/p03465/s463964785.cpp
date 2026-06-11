#include <bits/stdc++.h>
using namespace std;

bitset<4000001> b;

int n, s;

int main() {
	scanf("%d", &n);
	b[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		b |= b << x;
		s += x;
	}
	for (int i = (s + 1) / 2; i <= s; i++) {
		if (b[i]) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}
