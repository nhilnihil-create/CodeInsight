#include "bits/stdc++.h"
using namespace std;

//26
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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int g = 0;
	for (int i = 0; i < n; ++i) {
		g = __gcd(v[i],g);
	}
	cout << g;
} 	

