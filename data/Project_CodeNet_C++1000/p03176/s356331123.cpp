#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n;
ll h[N], a[N], tree[N], answer;
map<ll, ll> val;

void update(ll x, ll v) {
	for (; x <= N; x += x & -x) {
		tree[x] = max(tree[x], v);
	}
}

ll query(ll idx) {
	ll ret = -1e18;
	while (idx > 0) {
		ret = max(ret, tree[idx]);
		idx -= idx & -idx;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		val[h[i]] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		update(h[i], query(h[i]) + val[h[i]]);
	}
	for (int i = 1; i < N; i++) {
		answer = max(answer, tree[i]);
	}
	cout << answer;

	return 0;
}
