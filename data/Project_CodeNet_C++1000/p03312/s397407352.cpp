#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int max_n = 1e6;

ll n;

ll a[max_n];
ll s[max_n];

// 左端が0、 右端がrとr+1の間、真ん中がxとx+1の間のとき
// xを進めてもP, Qの差が大きくならないならtrue
bool condl(ll x, ll r){
	ll p1 = s[x] - s[0];
	ll q1 = s[r] - s[x];
	ll p2 = s[x+1] - s[0];
	ll q2 = s[r] - s[x+1];
	return abs(p2 - q2) <= abs(p1 - q1);
}

// 左端がlと1+1の間、 右端がn+1、真ん中がxとx+1の間のとき
// xを小さくしてもR(変数はp), S(変数はq)の差が大きくならないならtrue
bool condr(ll x, ll l){
	ll p1 = s[x] - s[l];
	ll q1 = s[n] - s[x];
	ll p2 = s[x-1] - s[l];
	ll q2 = s[n] - s[x-1];
	return abs(p2 - q2) <= abs(p1 - q1);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	rep(i, n) cin >> a[i+1];
	s[0] = 0;
	rep(i, n) s[i+1] = s[i] + a[i+1];

	// P, Qについて確認
	ll fl[n+1];
	// 真ん中をi,i+1の間のしたとき,
	// 左側はfl[i]とfl[i]+1の間で切るのが最適

	ll left = 1;
	for (ll right = 1; right <= n; ++right) {
	    while (left < right && condl(left, right)) {
	        ++left;
	    }
	    fl[right] = left;
	}

	// R, Sについて確認
	ll fr[n];
	// 真ん中をi,i+1の間のしたとき,
	// 右側はfr[i]とfr[i]+1の間で切るのが最適

	ll right = n;
	for (ll left = n; left >= 1; --left) {
	    while (right > left && condr(right, left)) {
	        --right;
	    }
	    fr[left] = right;
	}

	// 各真ん中でP, Q, R, S(変数はt)の最大値と最小値の差の絶対値を比較してゆく
	ll ans = 1e15;
	for(ll i = 1; i <= n; i++){
		ll p = s[fl[i]] - s[0];
		ll q = s[i] - s[fl[i]];
		ll r = s[fr[i]] - s[i];
		ll t = s[n] - s[fr[i]];

		ans = min(ans, max({p, q, r, t}) - min({p, q, r, t}));
	}

	cout << ans << endl;
}
