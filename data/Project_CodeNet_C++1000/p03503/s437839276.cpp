#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//const ll p = 1e9 + 7;
	//const ll p = 998244353;

	ll n;
	cin >> n;
	vector<vector<bool>> f(n, vector<bool>(10));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < 10; j++) {
			ll x;
			cin >> x;
			f[i][j] = (x == 1);
		}
	}
	vector<vll> p(n, vll(11));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < 11; j++) cin >> p[i][j];
	}

	vector<bool> v(10, false);
	v[9] = true;
	ll ans = -1e10;
	for (ll i = 0; i < 1023; i++) {
		ll subans = 0;
		for (ll j = 0; j < n; j++) {
			ll cnt = 0;
			for (ll k = 0; k < 10; k++) {
				if (f[j][k] && v[k]) cnt++;
			}
			subans += p[j][cnt];
		}
		ans = max(ans, subans);
		if (i == 1022) break;
		ll x = 9;
		while (x >= 0 && v[x]) {
			v[x] = false;
			x--;
		}
		v[x] = true;
	}
	cout << ans << endl;
}
