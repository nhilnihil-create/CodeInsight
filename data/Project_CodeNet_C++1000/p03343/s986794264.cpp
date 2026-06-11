#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T> using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (1 << 11), K = 11;
int n, k, q, a[N], val[N], used[N], m;
vector <int> pos[N];
int par[N];
multiset <int> st[N];

struct Fen {
	int f[N], sz = 0;
	Fen() {
		memset(& f, 0, sizeof(f));
	}
	void upd(int x, int y) {
		sz += y;
		for (; x < (1 << K); x |= (x + 1))
			f[x] += y;
	}
	int kth(int k) {
		if (sz < k)
			return -1;
		int cur = 0, s = 0;
		for (int i = (1 << (K - 1)); i > 0; i >>= 1)
			if (s + f[cur + i - 1] < k)
				s += f[cur + i - 1], cur += i;
		return cur;
	}
};
Fen F;

void upd(int x) {
	while ((int)st[x].size() > k - 1) {
		F.upd(*st[x].begin(), 1);
		st[x].erase(st[x].begin());
	}
}

void make_set(int x) {
	par[x] = x;
	st[x].insert(a[x]);
}

int find_set(int x) {
	if (x == par[x]) return x;
	return par[x] = find_set(par[x]);
}

void union_set(int x, int y) {
	x = find_set(x), y = find_set(y);
	if (x == y) return;
	if ((int)st[x].size() < (int)st[y].size())
		swap(x, y);
	par[y] = x;
	for (int i : st[y])
		st[x].insert(i);
	st[y].clear();
	upd(x);
}

void add(int x) {
	upd(x);
	used[x] = 1;
	if (used[x - 1])
		union_set(x - 1, x);
	if (used[x + 1])
		union_set(x, x + 1);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> k >> q;
	vector <int> b;
	for (int i = 1; i <= n; i++) cin >> a[i], b.pb(a[i]);
	sort(all(b));
	b.erase(unique(all(b)), b.end());
	m = b.size();
	for (int i = 1; i <= n; i++) {
		int x = lower_bound(all(b), a[i]) - b.begin() + 1;
		val[x] = a[i];
		a[i] = x;
		pos[x].pb(i);
		make_set(i);
	}
	int ans = 1e9;
	for (int i = m; i >= 1; i--) {
		for (int j : pos[i])
			add(j);
		int x = F.kth(q);
		if (x != -1)
			ans = min(ans, val[x] - val[i]);
	}
	cout << ans;
}
