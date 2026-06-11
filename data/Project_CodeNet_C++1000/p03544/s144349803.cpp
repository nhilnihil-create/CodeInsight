#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() { 
	ll n;
	cin >> n;
	if (n == 1) {
		cout << 1;
	}else {
		ll l1 = 2;
		ll l2 = 1;
		for (ll i = 2; i <= n; ++i) {
			//l1 = l2;
			ll a = l2;
			l2 = l2 + l1;
			l1 = a;
		}
		cout << l2;
	}
}
