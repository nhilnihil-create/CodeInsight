/*
 * Bad Move
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

const int N = 1e5 + 5, K = 205, MOD = 998244353;
const ll MX = 1e15;
const int blkSz = 320;
int n;
vector<ll> L, R;
int main() {
//#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//#endif

	cin >> n;
	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		L.pb(l);
		R.pb(r);
	}
	L.pb(0), R.pb(0);

	sort(L.rbegin(), L.rend());
	sort(R.begin(), R.end());
	ll ans = 0;

	for(int i = 0; i < n && 2 * (L[i] - R[i]) >= 0; i++){
		ans += 2 * (L[i] - R[i]);
	}

	cout << ans << '\n';

	return 0;
}
