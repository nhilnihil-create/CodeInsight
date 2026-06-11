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

const int N = 200003;
int n, a[2][N], b[2][N];

ll get(int x) {
	ll res = 0;
	for (int i = 0; i < n; i++)
		res += upper_bound(b[1], b[1] + n, x - a[1][i]) - b[1];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[0][i];
	for (int i = 0; i < n; i++) cin >> b[0][i];
	ll ans = 0;
	for (int i = 0; i < 29; i++) {
		int m = (1 << (i + 1)) - 1;
		for (int j = 0; j < n; j++)
			a[1][j] = a[0][j] & m, b[1][j] = b[0][j] & m;
		sort(a[1], a[1] + n), sort(b[1], b[1] + n);
		int ways = get(m) - get((1 << i) - 1) + get((1 << (i + 1)) + m) - get((1 << (i + 1)) + (1 << i) - 1);
		if (ways & 1) ans |= (1 << i);
	}
	cout << ans;
}
