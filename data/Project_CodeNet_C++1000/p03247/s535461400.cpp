#include <bits/stdc++.h>
#define lg2 std::__lg

const int N = 1054;

int n, L;
int X[N], Y[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

int main() {
	int i, j, x, y, parity = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d%d", X + i, Y + i), parity += (X[i] ^ Y[i]) & 1;
	if (parity && parity != n) return puts("-1"), 0;
	if (!parity) for (i = 0; i < n; --X[i++]);
	for (i = 0; i < n; ++i) up(L, abs(X[i]) + abs(Y[i]));
	L = (L ? lg2(L) + 1 : 0), printf("%d\n", L + !parity);
	for (i = L - 1; i >= 0; --i) printf("%d%c", 1 << i, !i && parity ? 10 : 32);
	if (!parity) putchar(49), putchar(10);
	for (i = 0; i < n; ++i, putchar(10)) {
		x = X[i], y = Y[i];
		for (j = L - 1; j >= 0; --j)
			putchar(abs(x) < abs(y)
				? (y >> 31 ? (y += 1 << j, 68) : (y -= 1 << j, 85))
				: (x >> 31 ? (x += 1 << j, 76) : (x -= 1 << j, 82))
			);
		if (!parity) putchar(82);
	}
	return 0;
}