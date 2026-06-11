#include <bits/stdc++.h>

using int64 = long long;

const int MAX_N = int(2e5) + 10;

int n;
bool is[MAX_N];
char s[MAX_N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'C' && s[i - 1] != 'B') {
			is[i] = true;
		}
		if (s[i] == 'B' && s[i + 1] != 'C') {
			is[i] = true;
		}
	}

	int64 ans = 0LL;
	for (int l = 1, r; l <= n; l = r + 1) {
		while (is[l]) ++l;
		if (l > n) break;
		r = l;
		while (r < n && !is[r + 1]) ++r;
		int cnt = 0;
		int64 del = 0LL;
		for (int i = l; i <= r; ++i) {
			if (s[i] == 'A') ++cnt;
			else if (s[i] == 'B' && s[i + 1] == 'C') {
				++i;
				del += cnt;
			}
		}
		ans += del;
	}

	std::cout << ans << std::endl;
}