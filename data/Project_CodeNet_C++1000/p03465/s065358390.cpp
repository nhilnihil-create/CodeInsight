#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri();
	int upper = std::accumulate(a, a + n, 0) / 2;
	std::bitset<2000001> bitset;
	bitset[0] = 1;
	for (int i = 0; i < n; i++) bitset |= bitset << a[i];
	int res;
	for (int i = upper; i >= 0; i--) if (bitset[i]) {
		res = i;
		break;
	}
	std::cout << std::accumulate(a, a + n, 0) - res << std::endl;
	return 0;
}
