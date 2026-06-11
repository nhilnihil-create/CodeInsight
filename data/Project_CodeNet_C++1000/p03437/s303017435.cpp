#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

int main()
{
	ll x, y;
	cin >> x >> y;
	ll power = 1;
	while (x <= 10e18 / power) {
		x *= power;
		if (x % y == 0) power++;
		else {
			cout << x << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
