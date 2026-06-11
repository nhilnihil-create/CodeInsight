#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define MP std::make_pair
#define PII std::pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CL(a, b) memset(a, b, sizeof a)
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, r, l) for (int i = (r); i >= (l); -- i)
#define PE(x, a) for (int x = head[a]; x;x = edge[x].next)

typedef long long ll;

const int MAXN = 2e5 + 7;

int t[MAXN], a[MAXN], n;

inline int lb(int x) {
	return x & (-x);
}

void add(int x) {
	for (int i = x; i <= 2 * n; i += lb(i)) t[i]++;
}

int query(int x) {
	int r = 0;
	for (int i = x; i; i -= lb(i)) r += t[i];
	return r;
}

bool check(int mid) {
	CL(t, 0);
	int sum = 0;
	ll cnt = 0;
	add(n);
	rep(i, 1, n) sum += (a[i] >= mid ? 1 : -1), cnt += query(sum + n), add(sum + n);
	return cnt >= 1ll * n * (n + 1ll) / 4ll;
}

int main() {
	scanf("%d", &n);
	int l = INT_MAX, r = INT_MIN, mid;
	rep(i, 1, n) scanf("%d", a + i), l = std::min(l, a[i]), r = std::max(r, a[i]);
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}