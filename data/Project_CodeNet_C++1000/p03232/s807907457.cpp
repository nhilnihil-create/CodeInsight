#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

const int N = 1e5 + 10;
const int Mod = 1e9 + 7;

int Pow(int x, int e) {
	int ret = 1;
	while (e) {
		if (e & 1) ret = 1ll * ret * x % Mod;
		x = 1ll * x * x % Mod;
		e >>= 1;
	}
	return ret;
}

int A[N], inv[N], n;

int main() {

	scanf("%d", &n);
	For(i, 1, n) scanf("%d", &A[i]);
	For(i, 1, n) inv[i] = (inv[i - 1] + Pow(i, Mod - 2)) % Mod;

	int ans = 0;
	For(i, 1, n) ans = (ans + 1ll * A[i] * (inv[i] + inv[n - i + 1] - 1)) % Mod;
	For(i, 1, n) ans = 1ll * ans * i % Mod;
	printf("%d\n", ans);

	return 0;
}