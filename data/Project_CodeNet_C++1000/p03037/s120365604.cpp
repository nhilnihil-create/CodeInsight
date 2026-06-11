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
#define prec fixed << setprecision(12)
#define test int t; cin >> t; while (t--)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;

void solve() {
	int n, m;
	cin >> n >> m;
	int ll = 1, rr = n;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		ll = max(l, ll);
		rr = min(r, rr);
	}
	cout << max(rr - ll + 1, 0ll) << "\n";
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// test
	solve();
	return 0;
}
