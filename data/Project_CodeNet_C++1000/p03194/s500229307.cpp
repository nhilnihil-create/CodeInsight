#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

ll fastPow(ll i, ll x)
{
	if (x == 0)return 1LL;
	if (x % 2 == 1)return i*fastPow(i, x - 1);
	else {
		ll ret = fastPow(i, x / 2);
		return ret*ret;
	}
}

int main()
{
	ll n, p;
	cin >> n >> p;
	ll ans = 0;
	if (p == 1) {
		cout << 1;
		return 0;
	}
	if (n == 1) {
		cout << p;
		return 0;
	}
	for (ll i = 1; pow(i, n) <= p; i++) {
		ll D = fastPow(i, n);
		if (p%D == 0)ans = max(ans, i);
	}
	cout << ans;
}