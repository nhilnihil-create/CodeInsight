#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 2e5 + 5;

int n, h[N], a[N];
ll seg[N << 2], ans;

void upd(int pos, ll val, int id = 1, int b = 0, int e = N) {
	if(e - b == 1) {
		seg[id] = max(seg[id], val);
		return;
	}
	int mid = (b + e) >> 1, lc = id * 2, rc = lc | 1;
	if(pos < mid)
		upd(pos, val, lc, b, mid);
	else
		upd(pos, val, rc, mid, e);
	seg[id] = max(seg[lc], seg[rc]);
}

ll get(int l, int r, int id = 1, int b = 0, int e = N) {
	if(l >= e || b >= r)
		return 0;
	if(l <= b && e <= r)
		return seg[id];
	int mid = (b + e) >> 1, lc = id * 2, rc = lc | 1;
	return max(get(l, r, lc, b, mid), get(l, r, rc, mid, e));
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		ll best = get(0, h[i]) + a[i];
		ans = max(ans, best);
		upd(h[i], best);
	}
	cout << ans << "\n";
}
