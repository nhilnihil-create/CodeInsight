#include<bits/stdc++.h>

#define LL long long
#define RG register

using namespace std;
template<class T> T gi() {
	T x = 0; bool f = 0; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') f = 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f ? -x : x;
}
const int N = 1e5 + 10;
int a[N], b[N], c[N], n;
struct node {
	int t[N << 8];
#define lson (o << 1)
#define rson (o << 1 | 1)
	void clear () { memset(t, 0, sizeof(t)); }
	void Modify(int o, int l, int r, int p) {
		t[o]++;
		if (l == r) return ;
		int mid = (l + r) >> 1;
		if (p <= mid) Modify(lson, l, mid, p);
		else Modify(rson, mid + 1, r, p);
	}
	int query(int o, int l, int r, int p) {
		if (l == r) return 0;
		int mid = (l + r) >> 1;
		if (p <= mid) return query(lson, l, mid, p);
		else return t[lson] + query(rson, mid + 1, r, p);
	}
} T;
LL check(int x) {
	T.clear();
	for (int i = 1; i <= n; i++)
		c[i] = c[i - 1] + (a[i] < x ? 1 : -1);
	LL res = 0;
	T.Modify(1, 0, 2 * N, N);
	for (int i = 1; i <= n; i++) {
		res += T.query(1, 0, 2 * N, c[i] + N);
		T.Modify(1, 0, 2 * N, c[i] + N);
	}
	return res;
}
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	n = gi<int>(); int m = n;
	for (int i = 1; i <= n; i++) a[i] = gi<int>(), b[i] = a[i];
	sort(b + 1, b + 1 + m); m = unique(b + 1, b + 1 + m) - b - 1;
	int l = 1, r = m;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(b[mid]) >= 1ll * (n + 1) * n / 4 + 1) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", b[l - 1]);
	return 0;
}
