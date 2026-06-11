#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int x = 1;
vector<ll> tree(1 << 20 + 1);
ll query(ll z) {
	int b  = 1 + x, c = z + x;
	ll ans = 0;
	while (b <= c) {
		if (b % 2 == 1) ans = max(tree[b++], ans);
		if (c % 2 == 0) ans  = max(tree[c--], ans);
		b /= 2;
		c /= 2;
	}
	return ans;

}
void update(ll z) {
	int b =  z / 2;
	while (b >= 1) {
		tree[b] = max(tree[2 * b], tree[2 * b + 1]);
		b /= 2;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<ll> h(n + 1), v(n + 1);
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> v[i];
	while (x < n)	 x = x << 1;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		tree[x + h[i]] = query(h[i]) + v[i];
		ans  = max(tree[x + h[i]], ans);
		update(x + h[i]);
	}
	cout << ans << '\n';
	return 0;
}


