#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int ac = 1e6 + 10, mod = 1e9 + 7;
ll X[ac];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a, b, c; cin >> a >> b >> c;
	int x, y; cin >> x >> y;
	ll o = 1e18;
	for (int i = 0; i < 1e6; i++)
	{
		ll s = i * c;
		s += max(0ll, (x - i / 2) * a) + max(0ll, (y - i / 2) * b);
		o = min(s, o);
	}
	cout << o << '\n';
}
