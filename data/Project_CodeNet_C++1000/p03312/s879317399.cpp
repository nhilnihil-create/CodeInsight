#include<bits/stdc++.h>

using namespace std;


typedef long long ll ;
const ll mk = 200055;
const ll logn  = 29;
const ll mod = 1e9 + 7;

#define endl "\n"
#define IOS  ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define pii pair<ll,ll>
#define pq priority_queue
#define UwU              uwu
#define UwU              Mikuwu
#define Miku             best_waifu
#define Miku_dancing     god_waving
#define Miku_singing     god_shaking
#define a_Miku           cho_doi_bot_ngu

ll n;
ll a[mk];
long long ans = 1e9;
long long pref[mk];

long long f(int pos, int i, int j) {
	if (!pos || pos >= i || j <= i || j == n)
		return 1e9;
	long long x1 = pref[pos], x2 = pref[i] - pref[pos], x3 = pref[j] - pref[i], x4 = pref[n] - pref[j];
	return max(max(x1, x2), max(x3, x4)) - min(min(x1, x2), min(x3, x4));
}

signed main () {
	cin >>n ;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	for (int i = 2; i <= n - 2; ++i) {
		int l = upper_bound(pref, pref + n + 1, pref[i] / 2) - pref;
		int r = upper_bound(pref, pref + n + 1, pref[i] + (pref[n] - pref[i]) / 2) - pref;
		for (int l1 = l - 1; l1 <= l; ++l1) {
			for (int l2 = r - 1; l2 <= r; ++l2)
				ans = min(ans, f(l1,i, l2));
		}
	}
	cout << ans;
}
