#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m, c;
	cin >> n >> m >> c;
	vector<ll> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];
	ll ct = 0;
	for (int i = 0; i < n; i++)
	{
		ll s = 0;
		for (int j = 0; j < m; j++)
		{
			ll x;
			cin >> x;
			s += x * b[j];
		}
		s += c;
		if (s > 0)
			ct++;
	}
	cout << ct;
	return 0;
}
