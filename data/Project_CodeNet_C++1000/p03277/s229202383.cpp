#include <bits/stdc++.h>
typedef long long ll;
const int N = 100005;
using std::cin;
using std::cout;

inline void up(int &x, int y) { x < y ? x = y : 0; }
inline void down(int &x, int y) { x > y ? x = y : 0; }
inline int max(const int x, const int y) { return x > y ? x : y; }
inline int min(const int x, const int y) { return x < y ? x : y; }

int n, a[100005], b[100005], c[100005];
namespace bit {
	int s[200010];
	inline void init() { memset(s, 0, sizeof s); }
	inline int lowbit(int x) { return x & -x; }
	inline void insert(int x) { for (; x <= 200010; x += lowbit(x) ) ++s[x]; }
	inline int query(int x, int ret = 0) { for (; x; x -= lowbit(x)) ret += s[x]; return ret; }
}

inline bool check(int x) {
	bit::init();
	ll s0 = 0;
	for (int i = 1; i <= n; ++i) c[i] = (a[i] >= x) ? 1 : -1;
	for (int i = 1; i <= n; ++i) c[i] = c[i - 1] + c[i];
	for (int i = 1; i <= n; ++i) bit::insert(c[i - 1] + 100005), s0 += bit::query(c[i] + 100005);
	s0 = s0 << 2;
	if (s0 >= 1ll * n * (n + 1)) return true;
	else return false;
}
inline int binary(int ret = 0) {
	int l, r;
	std::sort(b + 1, b + n + 1);
	r = std::unique(b + 1, b + n + 1) - b - 1;
	l = 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(b[mid])) ret = mid, l = mid + 1;
		else r = mid - 1;
	}
	return b[ret];
}
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
	cout << binary() << '\n';
	return 0;
}