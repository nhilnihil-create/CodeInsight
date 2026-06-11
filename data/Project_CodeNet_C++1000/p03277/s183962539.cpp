/// In The Name Of God

#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()

#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)

#define Kazakhstan ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define nl '\n'
#define ioi exit(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

int n;
int a[N], pr[N];

struct fenwick {
	int f[N];
	void clear() {
		memset(f, 0, sizeof(f));
	}
	void upd(int p, int x) {
		p += n;
		for (; p <= n + n; p |= p + 1) f[p] += x;
	}
	int get(int p) {
		int res = 0;
		p += n;
		for (; p >= 0; p = (p & (p + 1)) - 1) res += f[p];
		return res;
	}
} t;

ll cnt(int x) {
	ll res = 0;
	t.clear();
	rep(i, 1, n) {
		pr[i] = pr[i - 1] + (a[i] >= x ? 1 : -1);
		t.upd(pr[i - 1], 1);
		res += t.get(pr[i]);
		// rep(j, 1, i) res += (pr[i] >= pr[j - 1]);
	}
	return res;
}
int main() {
	#ifdef wws
		freopen ("in.txt", "r", stdin);
	#endif
	Kazakhstan
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
	}
	int l = 1, r = inf, ans = -1;
	ll atl = (ll)n * (n + 1) / 2;
	atl = atl - (atl / 2 + 1) + 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (cnt(mid) >= atl) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
	ioi
}
