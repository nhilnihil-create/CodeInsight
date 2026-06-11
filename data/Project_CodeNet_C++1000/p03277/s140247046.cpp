#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define x first
#define y second
#define all(x) begin(x), end(x)

typedef long long ll;
typedef long double ld;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using normal_queue = priority_queue<T, vector<T>, greater<T>>;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int l = -1, r = 1e9 + 1; //l <= ans, r > ans
	while (r - l > 1) {
		int mid = (l + r) / 2;
		ordered_set<pair<int, int>> pref_sums;
		pref_sums.insert({0, 0});
		int balance = 0;
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] >= mid)
				++balance;
			else
				--balance;
			ans += pref_sums.order_of_key({balance, n + 10});
			// cout << "for " << balance << " " << ans << "\n";
			pref_sums.insert({balance, i + 1});
		}
		// ll myans = 0;
		// for (int i = 0; i < n; ++i) {
		// 	ll summ = 0;
		// 	for (int j = i; j < n; ++j) {
		// 		if (a[j] >= mid)
		// 			++summ;
		// 		else
		// 			--summ;
		// 		if (summ >= 0)
		// 			++myans;
		// 	}
		// }
		// cout << mid << " -> " << ans << " " << myans << endl;
		// assert(myans == ans);
		// cout << mid << " -> " << ans << "\n";
		if (ans >= (ll(n) * (n + 1) / 2 + 1) / 2)
			l = mid;
		else
			r = mid;
	}
	cout << l << "\n";
	return 0;
}