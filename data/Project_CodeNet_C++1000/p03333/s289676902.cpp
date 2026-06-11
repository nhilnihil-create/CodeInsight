#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) + rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

using namespace std;

const int maxn = 2e5 + 10, Z = 1e5 + 5;

int n, m, l[maxn], r[maxn];
long long ans;

int main() {
	scanf("%d", &n);
	while(n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		++l[y + Z];
		++r[x + Z];
	}
	++l[Z];
	++r[Z];
	for (int i = 1; i < maxn; ++i) {
		l[i] += l[i - 1];
	}
	for (int i = maxn - 2; ~i; --i) {
		r[i] += r[i + 1];
	}
	for (int i = 0; i < maxn - 1; ++i) {
		ans += min(l[i], r[i + 1]);
	}
	printf("%"LLFORMAT"d\n", ans << 1);
	return 0;
}
