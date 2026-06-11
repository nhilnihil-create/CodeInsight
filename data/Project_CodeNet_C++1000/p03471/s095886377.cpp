#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	int n;
	cin >> n;
	ll val;
	cin >> val;
	for (ll i = 0; i <= n; ++i) {
		for (ll j = 0; j <= n; ++j) {
			ll k = n - i - j;
			if (k >= 0) {
				if (i * 10000 + j * 5000 + k * 1000 == val) {
					cout << i << " " << j << " " << k;
					return 0; 
				}
			}
		} 
	}
	cout << "-1 -1 -1";
}




