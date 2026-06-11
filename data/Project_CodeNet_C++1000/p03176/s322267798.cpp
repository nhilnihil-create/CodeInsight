#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxN = 2e5 + 5;
int N, h[mxN], a[mxN];
ll tree[4 * mxN];

ll query(int l, int r, int ql, int qr, int node) {
	if (ql > r || qr < l) {
		return 0;
	}
	if (ql <= l && qr >= r) {
		return tree[node];
	}
	int mid = l + (r - l) / 2;
	return max(query(l, mid, ql, qr, 2 * node), query(mid + 1, r, ql, qr, 2 * node + 1));
}

void update(int l, int r, int idx, ll val, int node) {
	if (l == r) {
		tree[node] = val;
	} else {
		int mid = l + (r - l) / 2;
		if (idx >= l && idx <= mid) {
			update(l, mid, idx, val, 2 * node);
		} else if (idx > mid && idx <= r) {
			update(mid + 1, r, idx, val, 2 * node + 1);
		}
		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ll val = a[i] + query(1, N, 1, h[i] - 1, 1);
		update(1, N, h[i], val, 1);
		ans = max(ans, val);
	}
	cout << ans;
	
	return 0;
}
