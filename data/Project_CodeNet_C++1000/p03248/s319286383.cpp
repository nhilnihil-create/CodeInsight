#include <bits/stdc++.h>
using namespace std;

int n;
char s[100010];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) s[i] -= '0';
	if (!s[1] || s[n]) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n >> 1; ++i)
		if (s[i] != s[n - i]) {
			puts("-1");
			return 0;
		}
	int j = 1;
	for (int i = 2; i <= n >> 1; ++i)
		if (s[i])
			for (; j < i; ++j)
				printf("%d %d\n", i, j);
	for (; j < n; ++j)
		printf("%d %d\n", j, n);
	return 0;
}
