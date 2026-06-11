#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define x first
#define y second
typedef long long ll;
typedef long double ld;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using normal_queue = priority_queue<T, vector<T>, greater<T>>;

const int MAX_N = 2e5 + 10;

char str[MAX_N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	int n = strlen(str);
	ll ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'W')
			ans += i - cnt, ++cnt;
	}
	cout << ans << "\n";
	return 0;
}