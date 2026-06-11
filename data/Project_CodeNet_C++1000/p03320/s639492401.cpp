#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll k, mn1 = 1e9, mn2 = 1;

ll f(ll p) {
	ll s;
	for (s = 0; p; s += p % 10, p /= 10);
	return s;
}

int main()
{
	ll i, j;
	cin >> k;
	for (i = 1, j = 1; k; i += j) {
		if (i * f(i + j) <= (i + j) * f(i)) printf("%lld\n", i), k--;
		else i -= j, j *= 10;
	}
    return 0;
}