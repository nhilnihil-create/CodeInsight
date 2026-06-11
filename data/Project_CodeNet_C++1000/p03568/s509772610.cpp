#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	ll all = 1;
	ll odd = 1;
	for (ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		if (a % 2) {
			odd *= 1;
			all *= 3;
		}
		else {
			odd *= 2;
			all *= 3;
		}
	}
	cout << all - odd << endl;
}
