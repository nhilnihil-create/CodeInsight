#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;

int n;
char s[MAXN];

int main() {
	scanf(" %s", s + 1), n = strlen(s + 1);
	if (s[1] == '0' || s[n] == '1') return puts("-1"), 0;
	for (int i = 1; i < n; ++i) if (s[i] != s[n - i]) return puts("-1"), 0;
	int lst = 1, now = 0;
	for (int i = 2; i <= n; ++i) if (s[i] == '1') {
		printf("%d %d\n", now = i, lst);
		for (int j = lst + 1; j < now; ++j) printf("%d %d\n", now, j);
		lst = now;
	}
	printf("%d %d\n", n, n - 1);
	return 0;
}