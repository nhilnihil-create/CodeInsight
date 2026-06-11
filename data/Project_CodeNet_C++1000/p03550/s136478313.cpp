#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
	ll n, z, w; cin >> n >> z >> w;
	vector<ll>a(n); for (auto&& x : a)cin >> x;
	ll ans = 0;
	if (n == 1) {
		ans = abs(a[0] - w);
	}
	else {
		ans = max(abs(a[n - 1] - w), abs(a[n - 2] - a[n - 1]));
	}
	cout << ans << endl;

	return 0;
}