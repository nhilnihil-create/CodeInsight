#include <algorithm>
#include <cstdio>
#define rg register
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
template < class T > inline void read(T& s) {
	s = 0; int f = 0; char c = getchar();
	while ('0' > c || c > '9') f |= c == '-', c = getchar();
	while ('0' <= c && c <= '9') s = s * 10 + c - 48, c = getchar();
	s = f ? -s : s;
}

typedef long long LL;
const int _ = 1e5 + 5;

int n, a[_], t[_], tmp[_]; LL ans;

inline void merge(int l, int r) {
	if (l == r) return ;
	int mid = (l + r) >> 1;
	merge(l, mid), merge(mid + 1, r);
	int i = l, j = mid + 1, p = l;
	while (i <= mid && j <= r) {
		if (t[i] < t[j]) {
			ans += mid - i + 1;
			tmp[p] = t[j], ++p, ++j;
		} else
			tmp[p] = t[i], ++p, ++i;
	}
	while (i <= mid) tmp[p] = t[i], ++p, ++i;
	while (j <= r) tmp[p] = t[j], ++p, ++j;
	for (rg int x = l; x <= r; ++x) t[x] = tmp[x];
}

inline bool check(int mid) {
	t[0] = 0;
	for (rg int i = 1; i <= n; ++i)
		t[i] = t[i - 1] + (a[i] <= mid ? 1 : -1);
	ans = 0, merge(0, n);
	return ans >= (LL) n * (n + 1) / 2 / 2 + 1;
}

int main() {
	read(n);
	int l = 1e9, r = 1;
	for (rg int i = 1; i <= n; ++i) read(a[i]), r = max(r, a[i]), l = min(l, a[i]);
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid; else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
