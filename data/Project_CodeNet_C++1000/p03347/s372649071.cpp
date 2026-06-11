#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll N = 2e5 + 100;
 
ll a[N];
 
int main() {
	ll n, ans = 0;
	cin >> n;
	for (ll i = 0; i < n; ++i)
		cin >> a[i];
	for (ll i = 0; i < n; ++i) {
		if (a[i] > i || (i != 0 && a[i - 1] + 1 < a[i])) {
			cout << "-1\n";
			return 0;
		}
	}
	for (ll i = 0; i < n - 1; ++i) {
		if (a[i] + 1 != a[i + 1])
			ans += a[i];
	}
	ans += a[n - 1];
	cout << ans << '\n';
}