#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		ll a, b; cin >> a >> b;
		ll r = (ll)sqrt(a * b), ans = r * 2;
		if (a != b)ans--;
		if (a * b <= r * r)ans--;
		if (a * b <= r * (r + 1))ans--;
		cout << ans << endl;
	}
	return 0;
}