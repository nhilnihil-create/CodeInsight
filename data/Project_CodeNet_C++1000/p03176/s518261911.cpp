/*
    JAI JAGANNATH!
*/
//@Author : zanj0
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<lli,lli>
#define vi              vector<lli>
#define mii             map<lli,lli>
#define pqb             priority_queue<lli>
#define pqs             priority_queue<lli,vi,greater<lli> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            lli x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void zanj0()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}
const lli N = 2e5 + 10;
const lli offset = 6;
lli BIT[N + 10];
void update(lli idx, lli val) {
	while (idx < N) {
		BIT[idx] = max(BIT[idx], val);
		idx += (idx & (-idx));
	}
}
lli query(lli idx) {
	lli ret = 0;
	while (idx > 0) {
		ret = max(BIT[idx], ret);
		idx -= (idx & (-idx));
	}
	return ret;
}

void solve() {
	lli n;
	cin >> n;
	lli ret = 0;
	vi dp(n + 1);
	vi val(n);
	vi h(n);
	for (lli i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (lli i = 0; i < n; i++) {
		cin >> val[i];
	}

	for (lli i = 0; i < n; i++) {

		dp[h[i]] = val[i] + query(offset + h[i] - 1);
		ret = max(dp[h[i]], ret);
		update(offset + h[i], dp[h[i]]);

	}
	cout << ret << endl;
}
int main()
{
	zanj0();
	solve();
	return 0;
}