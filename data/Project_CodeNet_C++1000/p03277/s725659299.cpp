#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100001;
int n, c[N * 21], s[N * 21], a[N];

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

void add(int x) {
	for (int i = x; i <= 2 * N; i += i & -i) c[i]++;
}

int query(int x) {
	int res = 0;
	for (int i = x; i > 0; i -= i & -i) res += c[i];
	return res;
}

bool check(int x) {
	memset(c, 0, sizeof(c));
	s[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] >= x) s[i] = s[i - 1] + 1;
		else s[i] = s[i - 1] - 1;
	}
	int res = 0;
	for (int i = 0; i <= n; ++i) {
		res += query(s[i] + N);
		add(s[i] + N);
	}
	return res >= (n + 1) * n / 4;
}

signed main() {
	n = read();
	int l = 0, r = 0, ans;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		r = max(r, a[i]);
	}
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}