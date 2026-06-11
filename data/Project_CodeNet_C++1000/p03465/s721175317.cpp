#include <bits/stdc++.h>
using namespace std;
int n, s;
bitset<4000021> f;
int main () {
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		f |= f << x;
		s += x;
	}
	for (int i = (s + 1) >> 1; i <= s; i++) {
		if (f[i]) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}