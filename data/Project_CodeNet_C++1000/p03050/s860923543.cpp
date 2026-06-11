#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll ans = 0;
	ll i = 1;
	while (i <= sqrt(n)) {
		if (n % i == 0) {
			ll b = n / i - 1;
			if (i < b)ans+= b;
		}
		i++;
	}
	cout << ans << endl;
}