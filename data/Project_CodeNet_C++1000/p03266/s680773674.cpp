#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll n,k;
	cin >> n >> k;
	ll ans = 0;
	ll kbai = n / k;
	ans += kbai*kbai*kbai;
	if (k%2==0) {
		ll lbai = (n-k/2) / k + 1;
		if (2*n<k) lbai = 0;
		ans += lbai*lbai*lbai;
	}
	cout << ans << endl;
	return 0;
}
