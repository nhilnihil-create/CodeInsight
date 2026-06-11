#include<iostream>
using namespace std;

const int N = 1005;
int n, tp, x[N], y[N];
bool d, ux[40], uy[40];

inline void calc(int x, bool* c) {
	bool fCheck = x < 0;
	if (fCheck)x = -x;
	c[30] = c[31] = 1;
	for (int i = 1; i <= 30; i++)c[i - 1] = x >> i & 1;
	if (fCheck)for (int i = 0; i < 31 + d; i++)c[i] ^= 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", x + i, &tp);
		y[i] = x[i] - tp, x[i] += tp;
		if (!i)d = x[i] & 1;
		if (x[i] & 1 ^ d || y[i] & 1 ^ d) return puts("-1"), 0;
	}
	printf("%d\n", 31 + d);
	for (int i = 0; i < 30; i++)printf("%d ", 1 << i);
	printf("%d", (1 << 30) - 1);
	puts(d ? " 1" : "");
	for (int i = 0; i < n; i++) {
		calc(x[i], ux), calc(y[i], uy);
		for (int j = 0; j < 31 + d; j++)putchar(ux[j] ? uy[j] ? 'R' : 'U' : (uy[j] ? 'D' : 'L'));
		puts("");
	}

	return 0;
}