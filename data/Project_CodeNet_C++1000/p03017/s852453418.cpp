#include <bits/stdc++.h>

const int MAX_N = int(2e5) + 10;

int n, a, b, c, d;
char s[MAX_N];

int main() {
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	scanf("%s", s + 1);
	if (c < d) {
		for (int i = a; i < d; ++i) {
			if (s[i] == '#' && s[i + 1] == '#') {
				puts("No");
				return 0;
			}
		}
		puts("Yes");
		return 0;
	} else {
		for (int i = a; i < c; ++i) {
			if (s[i] == '#' && s[i + 1] == '#') {
				puts("No");
				return 0;
			}
		}
		for (int i = b; i <= d; ++i) {
			if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
				puts("Yes");
				return 0;
			}
		}
		puts("No");
	}
}