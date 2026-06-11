#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	
	ll n;
	cin >> n;
	
	if (n & 1) {
		cout << n * 2 << '\n';
	} else
		cout << n << '\n';
	return 0;
}
