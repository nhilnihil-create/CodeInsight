#include <iostream>

const int N = 200000 + 7;

int n;
int a[N];

int check(int x) {
	static int pos[N], chr[N], top;

	auto split = [&](int p) {
		while (top && pos[top] >= p) --top;
		int c = chr[top + 1];
		if (pos[top] < p - 1) pos[++top] = p - 1, chr[top] = c;
		pos[++top] = p, chr[top] = c;
	};
	pos[top = 1] = a[1], chr[1] = 1;
	for (int i = 2; i <= n; ++i)
		if (a[i] > a[i - 1])
			pos[++top] = a[i], chr[top] = 1;
		else {
			split(a[i]);	
			while (top && chr[top] == x) --top;
			if (!top) return 0;
			split(pos[top]), ++chr[top];
			if (pos[top] < a[i]) pos[++top] = a[i], chr[top] = 1;
		}
	return 1;
}

int main() {
//	freopen("code.in", "r", stdin);
//	freopen("code.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	int l = 1, r = n, m;
	while (l < r)
		check(m = l + r >> 1) ? (r = m) : (l = m + 1);
	printf("%d", r);
	return 0;
}
