#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define db double
#define pb push_back
#define ppb pop_back
#define all(x) (x).begin(), (x).end()

template <typename T>
using pr = array <T, 2>;

template <typename T>
using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 123;
int n, dp[N], m[N];
int mn[1 << 26];
string s;
vector <int> v;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	v.pb(0);
	for (int i = 0; i < 26; i++) {
		v.pb(1 << i);
	}
	cin >> s;
	int n = s.size();
	memset(& dp, 0x3f, sizeof(dp));
	memset(& mn, 0x3f, sizeof(mn));
	dp[0] = 0, mn[0] = 0;
	for (int i = 1; i <= n; i++) {
		m[i] = m[i - 1] ^ (1 << (s[i - 1] - 'a'));
		for (int j : v) {
			dp[i] = min(dp[i], mn[m[i] ^ j] + 1);
		}
		mn[m[i]] = min(mn[m[i]], dp[i]);
	}
	cout << dp[n];
}
