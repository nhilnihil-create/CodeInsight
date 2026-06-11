//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	ll n, k;
	cin >> n >> k;
	vll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	vector<vector<bool>> v(n, vector<bool>(48, false));
	for (ll i = 0; i < n; i++) {
		ll power2 = pow(2, 47);
		for (ll j = 0; j < 48; j++) {
			if (a[i] >= power2) {
				v[i][j] = true;
				a[i] -= power2;
			}
			power2 /= 2;
		}
	}

	vector<bool> kk(48, false);
	ll power2 = pow(2, 47);
	for (ll j = 0; j < 48; j++) {
		if (k >= power2) {
			kk[j] = true;
			k -= power2;
		}
		power2 /= 2;
	}

	bool broke = false;
	for (ll i = 0; i < 48; i++) {
		if (!broke) {
			if (kk[i]) {
				ll x = 0, y = 0;
				for (ll j = 0; j < n; j++) {
					if (v[j][i]) x++;
					else y++;
				}
				if (x >= y) {
					kk[i] = false;
					broke = true;
				}
			}
		}
		else {
			ll x = 0, y = 0;
			for (ll j = 0; j < n; j++) {
				if (v[j][i]) x++;
				else y++;
			}
			kk[i] = !(x >= y);
		}
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		power2 = pow(2, 47);
		for (ll j = 0; j < 48; j++) {
			if (v[i][j] ^ kk[j]) ans += power2;
			power2 /= 2;
		}
	}
	cout << ans << endl;
}
