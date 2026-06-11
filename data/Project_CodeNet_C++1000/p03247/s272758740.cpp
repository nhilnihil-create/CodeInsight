#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1005;

template <typename T>
T __abs(T x) {
	return x < 0 ? -x : x;
}

int n, m, D;
int X[N], Y[N];
int d[40];
map<int, char> G;

int sgn1[40], sgn2[40];

void work(int val, int* sgn) {
	for (int i = 1; i <= m; i++)
		sgn[i] = 1;
	for (int i = m; i; i--) {
		if (val >= d[i]) {
			val -= d[i];
			sgn[i] = -1;
		}
	}
}

int main() {
	scanf("%d", &n);
	G[1 * 2 + 1] = 'R';
	G[-1 * 2 - 1] = 'L';
	G[1 * 2 - 1] = 'U';
	G[-1 * 2 + 1] = 'D';
	for (int i = 1, x, y, tmp; i <= n; i++) {
		scanf("%d%d", &x, &y);
		X[i] = x + y, Y[i] = x - y;
		tmp = __abs(x) + __abs(y);
		if (i > 1 && ((tmp & 1) ^ (D & 1))) {
			puts("-1");
			return 0;
		}
		D = max(D, tmp);
	}
	if (!D)
		D = 2;
	int tmp = D, pw2 = 1;
	while (tmp >= pw2) {
		d[++m] = pw2;
		tmp -= pw2;
		pw2 <<= 1;
	}
	if (tmp)
		d[++m] = tmp;
	printf("%d\n", m);
	for (int i = 1; i <= m; i++)
		printf("%d ", d[i]);
	putchar('\n');
	for (int i = 1; i <= n; i++) {
		work(((long long) D - X[i]) >> 1, sgn1);
		work(((long long) D - Y[i]) >> 1, sgn2);
		for (int j = 1; j <= m; j++) {
			putchar(G[sgn1[j] * 2 + sgn2[j]]);
		}
		putchar('\n');
	}
	return 0;
}
