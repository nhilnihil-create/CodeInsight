#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 1e5 + 10;
using namespace std;

int n, m, T, kase = 1;

ll f(ll x) {
	ll ans = 0;
	while(x) { ans += x % 10; x /= 10; }
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	ll ans = 1, p = 1, num = 1;
	while(num <= n) {
		cout << ans << endl;
		ll a1 = ans + p;
		ll a2 = ans + p * 10;
		if(a1 * f(a2) <= a2 * f(a1)) ans = a1;
		else { ans = a2; p *= 10; }
		num++;
	}
	return 0;
}