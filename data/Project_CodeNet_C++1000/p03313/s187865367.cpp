/*
 * Code be weshen zyk :'(
 */
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using orderd_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define S second
#define F first
#define pb push_back

using ii = pair<int, int>;
using ll = long long;
using db = long double;

const int N = 18, K = 205, MOD = 1e9 + 7;
const int MX = 1e8;
const int blkSz = 320;
int a[1 << N];
int n;
ii dp[N][1 << N];
bool vis[N][1 << N];
ii solve(int bit, int mask) {
	if (bit == n)
		return ii(a[mask], 0);
	ii &ret = dp[bit][mask];
	if(vis[bit][mask])
		return ret;
	vis[bit][mask] = 1;
	ret = solve(bit + 1, mask);
	if(mask >> bit & 1){
		auto x = solve(bit + 1, mask ^ (1 << bit));
		if(x.F > ret.F)
			ret.S = ret.F, ret.F = x.F;
		else if(x.F > ret.S)
			ret.S = x.F;
		if(x.S > ret.S)
			ret.S = x.S;
	}
	return ret;
}
int main() {
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif

	cin >> n;

	for(int i = 0; i < ( 1 << n ); i++)
		cin >> a[i];

	int ans = 0;

	for(int i = 1; i < (1 << n); i++){
		ans = max(ans, solve(0,i).F + solve(0,i).S);
		cout << ans << '\n';
	}

	return 0;
}
