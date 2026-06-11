#include <bits/stdc++.h>

typedef std::map <int, int> map;
const int N = 200054;

int n, a[N];
map M;

inline bool check(int B) {
	int i, L = a[1]; bool result;
	map::iterator it; M.clear();
	for (i = 2; i <= n; ++i) if (a[i] <= L) {
		for (L = a[i]; !M.empty(); )
			if (it = --M.end(), it->first >= L) M.erase(it);
			else if (it->first == L - 1 && it->second == B - 1) M.erase(it), --L;
			else break;
		if (!L) return false;
		std::tie(it, result) = M.emplace(L - 1, 1);
		if (!result) ++it->second;
	} else L = a[i];
	return true;
}

int main() {
	int i, L, R, M; bool incr = true;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) if (scanf("%d", a + i), a[i] <= a[i - 1]) incr = false;
	if (incr) return putchar(49), putchar(10), 0;
	for (L = 2, R = n; L < R; check(M = (L + R) / 2) ? R = M : L = M + 1);
	printf("%d\n", L);
	return 0;
}