#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const ll inf = 2e18;
const int mod = 1e9 + 7;
const int N = 2e4 + 10;

int dp[N];

bool cmp(const pair<pii, int> &a, const pair<pii, int> &b) {
	return a.fi.fi + a.fi.se < b.fi.fi + b.fi.se;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	pair<pii, int> a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
	}
	sort(a, a + n, cmp);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = a[i].fi.se; j >= 0; j--) {
			if(dp[j] != -1) {
				dp[j + a[i].fi.fi] = max(dp[j + a[i].fi.fi], dp[j] + a[i].se);
				ans = max(ans, dp[j + a[i].fi.fi]);
			}
		}
	}
	cout << ans;

	return 0;
}