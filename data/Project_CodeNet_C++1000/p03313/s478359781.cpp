#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1 << 18;
struct S {
	int fir, sec;
	explicit S(int _f = 0, int _s = 0) { fir = _f, sec = _s; }
	void insert(int x) {
		if (x > fir) sec = fir, fir = x;
		else if (x > sec) sec = x;
	}
	void merge(const S & b) {
		insert(b.fir);
		insert(b.sec);
	}
} f[MAXN];
int n;
int main() {
	scanf("%d", &n);
	const int lim = 1 << n;
	for (int i = 0; i != lim; ++i) scanf("%d", &f[i].fir);
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != lim; ++j)
			if (!(j >> i & 1))
				f[j | 1 << i].merge(f[j]);
	int ans = 0;
	for (int i = 1; i != lim; ++i) {
		ans = std::max(ans, f[i].fir + f[i].sec);
		printf("%d\n", ans);
	}
	return 0;
}
