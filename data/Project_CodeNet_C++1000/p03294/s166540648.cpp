#include "bits/stdc++.h"
using namespace std;

//20
typedef long long ll;
			
int main() {
	int n;
	cin >> n;
	vector<ll> v(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	//}
	//ll x = v[0];
	//for (int i = 1; i < n; ++i) {
		//x = (x * v[i])/__gcd(x,v[i]);
	//}
	cout << sum - n;
}
