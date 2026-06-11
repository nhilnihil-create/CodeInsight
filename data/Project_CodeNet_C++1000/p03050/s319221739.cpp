#define rep(i, n) for(int i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll n;
	cin >> n;
	/*
	for (ll m=1;m<=n;m++) {
		ll p = n/m;
		ll r = n%m;
		printf("m=%3lld, p=%3lld, r=%3lld", m, p, r);
		if (p==r) printf(":same");
		printf("\n");
	}
	*/
	ll k_max = sqrt((double)n) + 1LL;
	ll ans = 0;
	for (ll k=1;k<=k_max;k++) {
		if (n%k==0) {
			ll m = n/k-1;
			if (m>=1 && k<=m-1) ans += m;
		}
	}
	cout << ans << endl;
	return 0;
}
