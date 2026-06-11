#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, h, w; cin >> n >> h >> w;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		if (h <= a && w <= b) ans++;
	}
	cout << ans << endl;
    return 0;
}