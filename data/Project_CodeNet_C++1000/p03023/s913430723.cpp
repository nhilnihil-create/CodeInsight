#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll mod = 1000000007;
ll bit[200010], num;
ll n;

ll sum(ll i)
{
	ll s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(ll i, ll x)
{
	while (i <= num)
	{
		bit[i] += x;
		i += i & -i;
	}
}

ll po(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2)
	{
		return po(x, y - 1) * x % mod;
	}
	else
	{
		ll yyy = po(x, y / 2);
		return yyy * yyy % mod;
	}
}

ll div(ll x)
{
	return po(x, mod - 2);
}

int main(void)
{
	cin >> n;
	cout << (n - 2) * 180 << endl;
	int www;
	cin >> www;
}
