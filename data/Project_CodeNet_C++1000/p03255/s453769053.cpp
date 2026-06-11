#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 119<<23|1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, x;
ll l[maxn], dp[maxn], pref[maxn], lp[maxn];
ll get(ll l, ll r) {
	return lp[r] - lp[l-1];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> l[i], lp[i] = l[i] + lp[i-1];
	ll ans = 1ll<<60;
	for(int a = n; a; a--) {
		ll cur = 0;
		/** O(n)
		for(ll t = 0, u = 1, i = n; i; i--) {
			if(u==1) cur += 2ll*l[i];
			cur += (2ll*u + 1)*l[i];
			if(++t == a) u++, t = 0;
		}
		**/
		/** O(n/a). sum_{a = 1..n} ( n/a ) = O(n * log(n)) **/
		ll r = n, l, u = 1;
		while(r > 0) {
			l = max(1ll, r-a+1);
			ll s = get(l, r);
			cur += (u==1)*2ll*s;
			cur += (2ll*u + 1)*s;
			if(cur > ans) break;
			u++;
			r = l-1;
		}
		
		ans = min(ans, cur + a*x);
	}
	cout << ans + n*x;
}
//
