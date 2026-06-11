#include <bits/stdc++.h>
using namespace std;

int n;
int a[2005];
bitset <3000000> memo;
int sum;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
	memo[0] = 1;
	for (int i = 0; i < n; i++) memo |= memo << a[i];
	for (int i = (sum + 1) / 2; i <= sum; i++) if (memo[i]) {
		printf("%d\n", i); break;
	}
	return 0;
}
