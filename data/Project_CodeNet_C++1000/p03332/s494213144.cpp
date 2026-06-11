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

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define S second
#define F first
#define pb push_back

using ii = pair<int, int>;
using ll = long long;
using db = long double;

const int N = 3e5 + 5, K = 205, MOD = 998244353;
const ll MX = 1e15;
const int blkSz = 320;
int fast(int b, int e) {
	if (!e)
		return 1;
	if (e & 1)
		return 1ll * b * fast(b, e - 1) % MOD;
	return fast(1ll * b * b % MOD, e >> 1);
}
ll F[N], iF[N];
ll C(int n, int k){
	if(k > n)
		return 0;
	return F[n] * iF[k] % MOD * iF[n-k] % MOD;
}
int main() {
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif

	ll n, a, b, k;
	cin >> n >> a >> b >> k;

	F[0] = iF[0] = 1;
	for (int i = 1; i < N; i++) {
		F[i] = F[i - 1] * i % MOD;
		iF[i] = fast(F[i], MOD - 2);
	}

	ll ans = 0;

	for (ll i = 0; i <= n && i * a <= k; i++) {
		if ((k - i * a) % b == 0) {
			ans += C(n, i) * C(n, (k - i * a) / b) % MOD;
			if(ans >= MOD)
				ans -= MOD;
		}
	}

	cout << ans << '\n';

	return 0;
}
