#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll k;

ll s(ll x)
{
	ll s = 0;
	while (x)
    {
        s += x % 10;
        x /= 10;
    }
	return s;
}

int main()
{
    ll d = 1, n = 1;

	cin >> k;
	cout << "1\n";
	while(--k) {
		if ((n + d * 10) * s(n + d) < (n + d) * s(n + d * 10))
            d *= 10;
		cout << (n += d) << "\n";
	}
	return 0;
}
