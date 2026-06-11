#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

static const double PI = 3.14159265358979;
static const ll MOD = 1e9 + 7;
static const ll INF = (ll)1 << 62;

bool Prime[1000001] = {};
void createPrime() {
	ll n = 1000001;
	rep(i, 0, n) Prime[i] = true;
	Prime[0] = false;
	Prime[1] = false;
	rep(i, 2, n) {
		if (Prime[i]) {
			rep(j, 2, n) {
				if (j*i >= n)break;
				Prime[j*i] = false;
			}
		}
	}
}
bool isPrime(ll n) {
	rep(i, 2, sqrt(n)) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
ll POW(ll n, ll p) {
	if (p == 0)return 1;
	if (p == 1)return n;

	ll t = POW(n, p / 2);
	//if (p & 1) return (t * t % MOD) * n % MOD;
	//else return t * t % MOD;
	if (p & 1) return (t * t) * n;
	else return t * t;
}
int main() {
	ll n, p; cin >> n >> p;
	map<ll, ll> mp;
	createPrime();

	if (n == 1) {
		cout << p << endl;
		return 0;
	}

	if (isPrime(p)) {
		cout << 1 << endl;
		return 0;
	}

	repe(i, 2, sqrt(p)) {
		if (Prime[i] && p % i == 0) {
			ll cnt = 0;
			ll k = p;
			while (k) {
				if (k % i == 0) {
					k /= i;
					cnt++;
				}
				else {
					break;
				}
			}
			mp[i] = cnt;
		}
	}

	ll ans = 1;
	for (map<ll, ll>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second >= n) {
			ll t = it->second / n;
			t = POW(it->first, t);
			ans *= t;
		}
	}
	cout << ans << endl;

	return 0;
}