#include <bits/stdc++.h>

using namespace std;
int n;
int s(long long x) {
	int sum = 0;
	while (x) sum += x % 10, x /= 10;
	return sum;
}
long long stk[1000001];
int top = 0;
int main( ) {
	for (int i = 1; i <= 100000; i ++) {
		while (top && 1LL * stk[top] * s(i) > 1LL *i * s(stk[top])) -- top;
		stk[++ top] = i;
	}
	for (int r = 0; r * 10000 + 109999 <= 99999999; ++ r) {
		int i = r * 10000 + 109999;
		while (top && 1LL * stk[top] * s(i) > 1LL *i * s(stk[top])) -- top;
		stk[++ top] = i;
	}
	for (int r = 0; 1LL * r * 10000000 + 109999999 <= 99999999999LL; ++ r) {
		long long i = 1LL * r * 10000000 + 109999999;
		while (top && 1LL * stk[top] * s(i) > 1LL *i * s(stk[top])) -- top;
		stk[++ top] = i;
	}
	for (int r = 0; r <= 1000000; ++ r) {
		long long i = 1LL * r * 10000000000 + 109999999999;
		while (top && 1LL * stk[top] * s(i) > 1LL *i * s(stk[top])) -- top;
		stk[++ top] = i;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		printf("%lld\n", stk[i]);
	return 0;
}
