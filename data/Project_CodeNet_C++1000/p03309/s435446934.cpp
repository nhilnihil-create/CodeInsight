#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long

ll myabs(ll x)
{
	return (x > 0 ? x : -x);
}

int main()
{
	int n = 0;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] -= (i + 1);
	}
	sort(a.begin(), a.end());
	int ix = n / 2;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		//cout << a[i] << " " << a[ix] << endl;
		ans += myabs(a[i] - a[ix]);
	}
	cout << ans << endl;
}
