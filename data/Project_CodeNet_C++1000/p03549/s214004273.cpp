#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class Type>
Type Pow(Type a, Type n)
{
	ll res = 1;
	while (0 < n) {
		if (n & 1) res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main()
{
	ll n, m;
	cin >> n >> m;
	cout << (1900 * m + 100 * (n - m))*Pow(2LL, m) << endl;
}
