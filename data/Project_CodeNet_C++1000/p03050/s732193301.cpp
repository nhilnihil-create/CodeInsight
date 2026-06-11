#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	ll n; cin >> n;
	ll sum = 0;

	ll i = 1;
	for(; i * i < n; i++) {
		if(n / i == n % i)sum += i;
	}

	for(; i >= 1; i--) {
		ll tmp = (n - i);
		if(tmp == 0)continue;
		ll m = tmp / i;
		if(tmp % i)continue;
		if(n / m == n % m)sum += m;
	}
	cout << sum << endl;
}