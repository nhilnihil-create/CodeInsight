#include "bits/stdc++.h"
using namespace std;

//28
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
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int minn = 1e9 + 7;
	sort(v.begin(),v.end());
	for (int i = k - 1; i < n; ++i) {
		minn = min(v[i] - v[i - k + 1],minn);
	}
	cout <<minn;
} 	

