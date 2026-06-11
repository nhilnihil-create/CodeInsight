#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
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
#define mod1 998244353
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define prec fixed << setprecision(12)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define test int t; cin >> t; while(t--)

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;

int _x[] = {0, 0, -1, 1, -1, 1, -1, 1};
int _y[] = { -1, 1, 0, 0, 1, -1, -1, 1};

void solve() {
	int n, k;
	cin >> n >> k;
	vi v(n);
	int idx;
	rep(i, 0, n - 1) {
		cin >> v[i];
		if (v[i] == 1) {
			idx = i;
		}
	}
	if ((n - 1) % (k - 1) == 0) cout << (n - 1) / (k - 1);
	else cout << (n - 1) / (k - 1) + 1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// test
	solve();

	return 0;
}
