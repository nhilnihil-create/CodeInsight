#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl '\n'
ll power(ll x, ll y, ll p)
{ 
    ll res = 1;  
    x = x % p;
    while (y > 0) { 
        if (y & 1) res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p;   
    } 
    return res; 
}
ll value (ll v1, ll v2, ll v3, ll v4) {
	ll a = max(v1, v2);
	a = max(a, v3);
	a = max(a, v4);
	ll b = min(v1, v2);
	b = min(b, v3);
	b = min(b, v4);
	return a - b;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n;
 	cin >> n;
 	vector <ll> pref(n + 1);
 	ll x;
 	pref[0] = 0;
 	for (ll i = 1; i <= n; i++) {
 		cin >> x;
 		pref[i] = pref[i - 1] + x;
 	}   
 	ll ans = 1e18;   
 	for (ll i = 3; i <= n - 1; i++) {
 		ll temp1 = pref[i - 1] / 2;
 		ll ind = lower_bound(all(pref), temp1) - pref.begin();
 		ll temp2 = (pref[n] - pref[i - 1]) / 2;
 		ll ind2 = lower_bound(all(pref), temp2 + pref[i - 1]) - pref.begin();
 		vector <ll> v1;
 		vector <ll> v2;
 		if (ind != 1) {
 			v1.pb(ind);
 		}
 		if (ind + 1 != i) {
 			v1.pb(ind + 1);
 		}
 		if (ind2 != i) {
 			v2.pb(ind2);
 		}
 		if (ind2 != n) {
 			v2.pb(ind2 + 1);
 		}
 		for (ll j = 0; j < sz(v1); j++) {
 			for (ll k = 0; k < sz(v2); k++) {
 				ans = min(ans, value(pref[i - 1] - pref[v1[j] - 1], pref[v1[j] - 1], pref[n] - pref[v2[k] - 1], pref[v2[k] - 1] - pref[i - 1]));
 			}
 		}
 	}
 	cout << ans << endl;
	return 0;
}