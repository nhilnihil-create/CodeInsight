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

const lli N = 16;
vector <lli> dp;
lli pre[1 << N];
lli arr[N][N];
lli n;
void ss()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}
void help(lli idx, vector <lli>& v, lli score, lli mask, lli newMask) {
	if (idx == v.size()) {
		dp[mask] = max(dp[mask], score + pre[newMask]);
		return;
	}
	help(idx + 1, v, score, mask, newMask);
	help(idx + 1, v, score, (mask ^ (1 << v[idx])), (newMask ^ (1 << v[idx])));
}
void solve() {
	lli n;
	cin >> n;
	dp.resize(1 << n, -inf);
	dp[0] = 0;
	for (lli i = 0; i < n; i++) {
		for (lli j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (lli mask = 0; mask < (1 << n); mask++) {
		pre[mask] = 0;
		for (lli i = 0; i < n; i++) {
			if (((mask >> i) & 1)) {
				for (lli j = i + 1; j < n; j++) {
					if (((mask >> j) & 1)) {
						pre[mask] += arr[i][j];
					}
				}
			}
		}
	}
	for (lli mask = 0; mask < (1 << n); mask++) {
		vector <lli> not_taken;
		for (lli i = 0; i < n; i++) {
			if (!((mask >> i) & 1)) {
				not_taken.pb(i);
			}
		}
		help(0, not_taken, dp[mask], mask, 0);
	}
	cout << dp[(1 << n) - 1] << endl;
}
int main()
{
	ss();
	solve();
	return 0;
}