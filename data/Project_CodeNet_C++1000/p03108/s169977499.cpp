#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
#define rep2(i, x) for(ll i = 1; i <= x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;

ll par[213456];//親
ll depth[213456];//木の深さ
ll tree_num[123456];
//n要素で初期化
void init(ll n) {
	for (int i = 0; i <= n; i++) {
		par[i] = i;
		depth[i] = 0;
		tree_num[i] = 1;
	}
}
//木の根を求める
ll find(ll x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
//xとyの属する集合を併合
void unite(ll x, ll y) {
	x = find(x); y = find(y);
	if (x == y) { return; }
	if (depth[x] < depth[y]) {
		par[x] = y; tree_num[y] += tree_num[x];
	}
	else {
		par[y] = x; tree_num[x] += tree_num[y];
		if (depth[x] == depth[y])depth[x]++;
	}
}
//xとyが同じ集合に属するか否か
bool same(ll x, ll y) {
	return find(x) == find(y);
}

ll a[123456], b[123456];
signed main() {
	ll n, m, cnt = 0; cin >> n >> m; init(n + m);
	rep(i, m) {
		cin >> a[i] >> b[i];
	}
	cnt = n * (n - 1) / 2;
	reverse(a, a + m); reverse(b, b + m);
	vector<ll> ans; ans.push_back(cnt);
	rep(i, m - 1) {
		if (!same(a[i], b[i])) {
			cnt -= tree_num[find(a[i])] * tree_num[find(b[i])];
		}
		ans.push_back(cnt);
		unite(a[i], b[i]);
	}
	reverse(all(ans));
	rep(i, m) {
		cout << ans[i] << endl;
	}
	return 0;
}