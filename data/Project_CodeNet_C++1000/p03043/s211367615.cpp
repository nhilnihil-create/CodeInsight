#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define in insert
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define prec fixed << setprecision(20)

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;

void solve() {
	ld n, k;
	cin >> n >> k;
	ld ans = 1 / n;
	ld ans2 = 0;
	for (int i = 1; i <= n; ++i) {
		int x = i;
		int cnt = 0;
		while (x < k)
			x *= 2, cnt++;
		ans2 += pow(0.5, cnt);
	}
	cout << prec << ans * ans2;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
//	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
	return 0;
}
