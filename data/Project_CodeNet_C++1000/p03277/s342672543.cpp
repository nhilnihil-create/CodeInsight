#include <bits/stdc++.h>

#define Set(a, b) memset(a, b, sizeof (a))
#define For(i, j, k) for (int i = j; i <= k; ++ i)

using namespace std;

typedef long long ll;

inline void File() {
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
}

const int N = 1e5 + 10, bas = 1e5, inf = 0x3f3f3f3f;
int a[N], n, s[N], ans, mx;

struct BIT {
	int c[N << 1], lim = N << 1; inline void init() { Set(c, 0); }	
	inline void update(int x, int v) { for (; x <= lim; x += x & -x) c[x] += v; }
	inline int query(int x) { int res = 0; for (; x; x -= x & -x) res += c[x]; return res; }
} T;

inline bool check(int x) {
	T.init(), Set(s, 0);
	For(i, 1, n) s[i] = s[i - 1] + (a[i] >= x ? 1 : -1);

	ll res = 0; T.update(bas, 1);
	For(i, 1, n) 
		res += T.query(s[i] + bas),
		T.update(s[i] + bas, 1);

	return res >= 1ll * n * (n + 1) / 4;
}

int main() {

	cin >> n;
	For(i, 1, n) scanf("%d", a + i), mx = max(mx, *(a + i));

	for (int l = 1, r = mx; l <= r; ) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	
	cout << ans << endl;
	return 0;
}
