#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

long long gcd (ll x, ll y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
 
long long lcm(ll x, ll y)
{
	return x * y / gcd(x, y);
}

signed main(void)
{
	int n, m;
	long long g, ans;
	string s, t;

	cin >> n >> m >> s >> t;
	ans = lcm(n, m);
	g = gcd(n, m);
	for(long long k = 0; k < g; k++)
	{
		if (s[k * n / g] != t[k * m / g])
			ans = -1;
	}
	cout << ans << endl;
	return 0;
}
