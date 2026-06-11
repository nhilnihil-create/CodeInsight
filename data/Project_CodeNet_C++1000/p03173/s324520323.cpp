#include<bits/stdc++.h>
using namespace std;
#define  vi vector<long long int>
#define  set1 set<long long int>
#define  pb push_back
#define  map1 map<long long int,long long int>
#define  ll    long long int
#define  mp make_pair
#define  inf 1e17
#define  minf INT_MIN
#define  setbits(x) __builtin_popcountll(x)
#define  pres(x,y) fixed<<setprecision(y)<<x
#define  pair1 pair<long long int,long long int>
#define  mk(arr,n,type) type *arr=new type[n];
#define  mod 1000000007
#define  pi  3.1415926535897932384626433832
#define  ins insert
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//find_by_order() --> returns an iterator to the k-th largest element (counting from zero)
//order_of_key()  --> the number of items in a set that are strictly smaller than our item.
#define  w(t) long long int t;t=1;while(t--)

ll dp[500][500];

ll sum1(ll	a[], ll x, ll b) {

	ll s = 0;
	for (ll i = x; i <= b; i++) {
		s += a[i];
	}
	return s;
}


ll solve1(ll a[], ll i, ll j) {

	if (i > j) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (i == j) {
		return dp[i][j] = 0;
	}

	ll mn = inf;
	for (ll k = i; k <= j - 1; k++) {

		ll temp = solve1(a, i, k) + solve1(a, k + 1, j) + sum1(a, i, j);
		mn = min(mn, temp);
	}

	return dp[i][j] = mn;
}
void solve() {

	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve1(a, 0, n - 1);


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(t) {
		solve();
	}
	return 0;
}