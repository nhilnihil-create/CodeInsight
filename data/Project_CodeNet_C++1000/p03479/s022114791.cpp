#include<iostream>
using namespace std;

typedef long long ll;

int main() {
	ll x, y; cin >> x >> y;

	int ans = 0;
	for (ll i = x; i <= y;) {
		i *= 2; ans++;
	}
	cout << ans << endl;

	return 0;
}