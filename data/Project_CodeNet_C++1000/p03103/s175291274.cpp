#include "bits/stdc++.h"
using namespace std;

//29
typedef long long ll;

ll power(ll a , ll b) {
    ll ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans  * a;
		}
		a = a * a;
		b  /= 2;
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<ll>> v(n,vector<ll> (2));
	for (int i = 0; i < n; ++i) {
		cin >> v[i][0] >> v[i][1];
	}
	sort(v.begin(),v.end());
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		if (k - v[i][1] > 0) {
			k -= v[i][1];
			sum += v[i][0] * v[i][1];
		}else {
			sum += v[i][0] * k;
			break;
		}
	}
	cout << sum;
} 	

