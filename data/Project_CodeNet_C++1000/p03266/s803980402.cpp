#include "bits/stdc++.h"
using namespace std;

//23
typedef long long ll;
			
int main() {
	ll a, b;
	cin >> a >> b;
	if (b % 2) {
		cout << (a/b) * (a / b) * (a / b);
	}else {
		ll p = (a - (b / 2)) / b; //
		if (a >= b / 2) p++;	
		ll e = (a / b) * (a / b) * (a / b);
		cout << (p * p * p) + e;
	}
}
