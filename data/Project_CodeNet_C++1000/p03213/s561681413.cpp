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

//素数判定
//#include <cmath>
bool is_prime(long long n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (long long i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	ll n;
	cin >> n;

	//n!を素因数分解
	vll v(n + 1, 0);
	for (ll i = 2; i <= n; i++) {
		if (is_prime(i)) {
			ll x = i;
			while (x <= n) {
				v[i] += n / x;
				x *= i;
			}
		}
	}

	ll cnt2 = 0, cnt4 = 0, cnt14 = 0, cnt24 = 0, cnt74 = 0;
	for (ll i = 2; i <= n; i++) {
		if (v[i] >= 2) cnt2++;
		if (v[i] >= 4) cnt4++;
		if (v[i] >= 14) cnt14++;
		if (v[i] >= 24) cnt24++;
		if (v[i] >= 74) cnt74++;
	}

	ll ans = 0;

	//p^74
	ans += cnt74;

	//p^2 * q^24
	ans += (cnt2 - cnt24) * cnt24;
	ans += cnt24 * (cnt24 - 1);

	//p^4 * q^14
	ans += (cnt4 - cnt14) * cnt14;
	ans += cnt14 * (cnt14 - 1);

	//p^2 * q^4 * r^4
	ans += cnt4 * (cnt4 - 1) / 2 * (cnt2 - cnt4);
	ans += (cnt4 - 1) * (cnt4 - 2) / 2 * cnt4;

	cout << ans << endl;
}
