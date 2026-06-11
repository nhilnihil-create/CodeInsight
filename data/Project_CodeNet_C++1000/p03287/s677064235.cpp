#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7, A = 1e5+5;

int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	ll a[n], ans = 0, acc = 0;
	map<ll, int> mop;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		acc = (acc + a[i]) % m;
		mop[acc]++;
	}
	acc = 0;
	for (int i = 0; i < n; i++)
	{
		ans += mop[acc];
		acc = (acc + a[i]) % m;
		mop[acc]--;
	}
	cout << ans;
	return 0;
}