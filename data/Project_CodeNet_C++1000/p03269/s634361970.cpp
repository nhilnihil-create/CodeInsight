#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * flag;
}

struct node {
	int a, b, v;
}e[61];
int tot, V;

void add(int x, int y, int v) {
	e[++tot].a = x;
	e[tot].b = y;
	e[tot].v = v;
}

int main() {
	int L = read();
	V = log(L) / log(2) + 1;
	for (int i = 1; i < V; ++i) {
		add(i, i + 1, 0);
		add(i, i + 1, 1 << (V - i - 1));
	}
	int u = 1 << (V - 1);
	for (int i = V - 1; i >= 1; --i) {
		if (L & (1 << (i - 1))) {
			add(1, V - i + 1, u);
			u += 1 << (i - 1);
		}
	}
	printf("%d %d\n", V, tot);
	for (int i = 1; i <= tot; ++i) {
		printf("%d %d %d\n", e[i].a, e[i].b, e[i].v);
	}
	return 0;
}