#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[4][4];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.rbegin(), a.rend());
	ll al = 0;
	ll bob = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			al += a[i];
		else
			bob += a[i];
	}
	cout << al - bob;
	return 0;
}
