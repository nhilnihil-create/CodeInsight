#include <bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;

#define debug printf("fuck %d\n", __LINE__);

inline LL read() {
	LL res = 0, bo = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') bo = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		res = (res << 1) + (res << 3) + ch - '0';
		ch = getchar();
	}
	return bo * res;
}

template <typename T>
void read(T &x) {
	x = read();
}

template <typename T, typename... Argv>
void read(T &a, Argv &... argv) {
	read(a);
	read(argv...);
}

const int N = 5005;
LL s[N], p[N], f[N];
int n, A, B;

int main() {
	memset(f, 0x3f, sizeof(f));
	read(n, A, B); f[0] = 0;
	for (int i = 1, x; i <= n; ++ i) {
		read(x);
		for (int j = 0; j <= n; ++ j) 
			if (j) p[j] = std::min(p[j - 1], f[j]);
			else p[j] = f[j];
		for (int j = 0; j <= x; ++ j) f[j] += A;
		for (int j = x + 1; j <= n; ++ j) f[j] += B;
		f[x] = std::min(f[x], p[x]);
	}
	LL ans = f[n + 1];
	for (int i = 0; i <= n; ++ i) ans = std::min(ans, f[i]);
	std::cout << ans << std::endl;
	return 0;
}