#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;

// a^n mod を計算する
ll modpow(ll a, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % 2019;
		a = a * a % 2019;
		n >>= 1;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	rep(i, s.size()) {
		if (s[i] == '+') {
			ans++;
		}
		else {
			ans--;
		}
	}

	cout << ans << endl;

	return 0;
}