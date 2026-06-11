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
int n, k, q, a[N], val[N], used[N], par[N], m;
vector <int> pos[N];
priority_queue <int> pq;
priority_queue <int, vector <int>, greater <int> > st[N];

void upd(int x) {
	while ((int)st[x].size() > k - 1) {
		pq.push(st[x].top());
		st[x].pop();
	}
}

void make_set(int x) {
	par[x] = x;
	st[x].push(a[x]);
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
	while (!st[y].empty()) {
		st[x].push(st[y].top());
		st[y].pop();
	}
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
		while ((int)pq.size() > q) pq.pop();
		if ((int)pq.size() == q)
			ans = min(ans, val[pq.top()] - val[i]);
	}
	cout << ans;
}
