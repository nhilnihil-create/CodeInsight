#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, h, w;
	cin >> n >> h >> w;
	vector<vector<ll>>ab(n, vector<ll>(2));
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		if (a >= h && b >= w)ans++;
	}
	cout << ans << endl;


}