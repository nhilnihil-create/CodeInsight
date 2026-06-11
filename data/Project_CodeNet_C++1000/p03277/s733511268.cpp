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

const int N = 2e5 + 123;
int n, a[N], b[N], p[N], f[N];

void upd(int x, int y) {
	for (; x <= 2 * n; x |= (x + 1))
		f[x] += y;
}

int getsum(int x) {
	int res = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		res += f[x];
	return res;
}

ll get(int x) {
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x) b[i] = 1;
		else b[i] = -1;
	}
	upd(n, 1);
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] + b[i];
		res += getsum(p[i] + n - 1);
		upd(p[i] + n, 1);
	}
	upd(n, -1);
	for (int i = 1; i <= n; i++)
		upd(p[i] + n, -1);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 0, r = 1e9 + 123;
	ll k = (ll)n * (n + 1) / 2;
	while (l < r - 1) {
		int mid = l + r >> 1;
		if (get(mid) >= k / 2 + 1)
			r = mid;
		else
			l = mid;
	}
	cout << r;
}
