#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 100005;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

char s[MAXN];
int n;

void gg() {
	puts("-1");
	exit(0);
}

inline void Edge(int u, int v) {
	printf("%d %d\n", u, v);
}

void init() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
}

void solve() {
	if (s[1] == '0') gg();
	if (s[n] == '1') gg();
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[n - i]) gg();
	}
	int cur = 1;
	for (int i = 2; i <= (n + 1) / 2; ++i) {
		if (s[i] == '0') continue;
		Edge(cur, i);
		for (int j = cur + 1; j < i; ++j) {
			Edge(j, i);
		}
		cur = i;
	}
	Edge(cur, cur + 1);
	for (int i = cur + 2; i <= n; ++i) {
		Edge(cur + 1, i);
	}
}

int main () {
	init();
	solve();
	return 0;
}
