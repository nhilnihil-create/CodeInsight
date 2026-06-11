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

const int N = 2e5 + 123, inf = 1e9 + 123;
int n, a[N], b[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	ll s = 0;
	int mn = inf;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i], s += a[i];
		if (a[i] > b[i]) mn = min(mn, b[i]);
	}
	if (mn == inf) cout << 0;
	else cout << s - mn;
}
