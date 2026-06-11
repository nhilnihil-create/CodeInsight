#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000007
#define SEP " "

ll		f0(ll b, ll md)
{
	ll ret = 0;
	if (b % 4 == 1 || b % 4 == 2)
		ret = (ll)1;
	ll p = 4;
	for (ll i = 1; i <= md; i++) {
		ll m = b % p;
		if (m >= p / 2 && m % 2 == 0)
			ret |= (((ll)1) << i);
		p *= 2;
	}
	return (ret);
}

ll		Xor(ll a, ll b, ll md)
{
	ll ret = 0;
	for (ll i = 0; i <= md; i++) {
		if ((a & (((ll)1) << i)) == (b & (((ll)1) << i)))
			ret &= ~(((ll)1) << i);
		else
			ret |= (((ll)1) << i);
	}
	return (ret);
}

int     main()
{
	ll a, b;
	cin >> a >> b;
	ll md = log2(b);
	ll f0a = f0(a, md);
	ll f0b = f0(b, md);
	ll tmp = Xor(f0a, f0b, md);
	ll fab = Xor(tmp, a, md);
	cout << fab << endl;
}

