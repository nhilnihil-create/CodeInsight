#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
const int N = 200005;

inline int input() {
	int x; char ch; while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

inline void chkmin(int &x, int y) { x = x < y ? x : y; }

int n;
int a[N];
int stk[N], cnt[N], top;

bool Push(int nu, int x) {
	if (!nu) return false;
	if (!top) {
		stk[++top] = nu, cnt[top] = 1;
		return true;
	}

	bool flag = false;
	while (top && stk[top] > nu) --top, flag = true;

	if (top && stk[top] == nu) {
		++cnt[top];
		if (cnt[top] > x) {
			--top;
			if (!Push(nu - 1, x)) return false;
			if (!Push(nu, x)) return false;
		}
	} else {
		stk[++top] = nu, cnt[top] = 1;
		if (flag) if (!Push(nu, x)) return false;
	}
	return true;
}

inline bool check(int x) {
	top = 0;
	if (x == 1) {
		for (int i = 2; i <= n; ++i)
			if (a[i] <= a[i - 1]) return false;
		return true;
	}
	for (int i = 1; i <= n; ++i)
		if (!Push(a[i], x)) return false;
	return true;
}

int main() {
#ifdef local
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
//	freopen("log", "w", stderr);
#endif
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	int l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}

	printf("%d\n", ans);
	return 0;
}