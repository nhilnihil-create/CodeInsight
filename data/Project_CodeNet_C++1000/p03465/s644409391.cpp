#include <bits/stdc++.h>
using namespace std;

const int N = 2000 * 2000 + 1;
bitset<N> mask;

int main() {
	int sum = 0;
	int n;
	scanf("%d", &n);
	mask.set(0);
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		mask = (mask << x) | mask;
		sum += x;
	}
        sum++;
	sum /= 2;
	while (!mask.test(sum)) sum++;
	printf("%d\n", sum);
}