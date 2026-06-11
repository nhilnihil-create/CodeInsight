#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
ll n, a, b, k, com[300010], ans;
const ll mod = 998244353;

ll pow(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2)
	{
		return pow(x, y - 1) * x % mod;
	}
	else
	{
		ll yyy = pow(x, y / 2);
		return yyy * yyy % mod;
	}
}

ll div(ll x)
{
	return pow(x, mod - 2);
}

int main(void)
{
	cin >> n >> a >> b >> k;
	com[0] = 1;
	for (ll i = 0; i < n; i++)
	{
		com[i + 1] = com[i] * (n - i) % mod * div(i + 1) % mod;
	}
	for (ll i = 0; i <= n; i++)
	{
		ll j = (k - a * i) / b;
		if (j <= n && j >= 0 && k == a * i + b * j)
		{
			(ans += (com[i] * com[j]) % mod) %= mod;
		}
	}
	cout << ans << endl;
	int www;
	cin >> www;
}
