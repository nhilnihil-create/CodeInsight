#include "bits/stdc++.h"
using namespace std;

//41
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> v(5);
	ll minn = 1e18;
	for (int i = 0; i < 5; ++i) {
		cin >> v[i];
		minn = min(minn,v[i]);
	}
	if (minn >= n) {
		cout << 5;
		return 0;
	}
	ll ans = ((n - minn) / minn); 
	if ((n - minn) % minn != 0) ans++;
	ans = ans + 5;
	cout << ans;  
}
