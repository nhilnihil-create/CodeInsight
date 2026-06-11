#include <bits/stdc++.h>

#define Set(a, b) memset(a, b, sizeof (a))
#define For(i, j, k) for (int i = j; i <= k; ++ i)
#define Forr(i, j, k) for (int i = j; i >= k; -- i)

using namespace std;

typedef long long ll;

inline int read() {
	int x = 0, p = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') p = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x * p;
}

inline void File() {
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
}

const int N = 1e5 + 10, bas = 1e5, inf = 0x3f3f3f3f;
int a[N], n, s[N], ans;

struct BIT {
	int c[N << 1], lim = N << 1; 

	inline void init() { Set(c, 0); }	
	
	inline void update(int x, int v) {
		for (; x <= lim; x += x & -x) c[x] += v;
	}

	inline int query(int x) {
		static int res;
		for (res = 0; x; x -= x & -x) res += c[x];
		return res;
	}
} T;

inline bool check(int x) {
	T.init(), Set(s, 0);
	For(i, 1, n) s[i] = s[i - 1] + (a[i] >= x ? 1 : -1);

	ll res = 0;
	T.update(bas, 1);
	For(i, 1, n) {
		res += T.query(s[i] + bas);
		T.update(s[i] + bas, 1);
	}

	return res >= 1ll * n * (n + 1) / 4;
}

int main() {

	n = read();

	int mx = 0;
	For(i, 1, n) mx = max(mx, a[i] = read());

	for (int l = 1, r = mx; l <= r; ) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	
	cout << ans << endl;
	return 0;
}
