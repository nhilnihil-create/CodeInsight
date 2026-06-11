#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll pow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll func(ll n) {
	if (n <= 0) return 0;

	ll ref = 1;
	ll beki = 0;
	while (true) {
		if (ref*2 > n) break;
		beki++;
		ref *= 2;
	}

	ll ret = 0;
	ref = 0;
	for (ll ii = beki; ii > 0; --ii){
		ll dummy = n;
		if ((n>>ii) & 1){
			ref += pow(2, ii);
			ll num = n - (ref - 1);
			if (num % 2 == 1){
				ret += pow(2, ii);
			}
		}
	}

	//0桁目は別途計算
	ll oneNum = (n+1)/2;
	if (oneNum % 2 == 1){
		ret += 1;
	}

	return ret;
}


int main() {
	ll A, B;
	cin >> A >> B;

	ll ans = func(B) ^ func(A-1);
	cout << ans << "\n";

	return 0;
}
