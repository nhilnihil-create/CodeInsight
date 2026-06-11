#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool L[600][600][300];
int main()
{
	ll n;
	cin >> n;
	vector<string> s(n);
	for (ll i = 0; i < n; i++)
		cin >> s[i];

	for (ll i = 0; i < n*2; i++)
	{
		for (ll j = 0; j < n*2; j++)
		{
			for (ll k = 1; k < n; k++)
			{
				L[i][j][k] = L[i][j][k - 1] | (s[(i + k) % n][j%n] != s[i%n][(j + k) % n]);
			}
		}
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			bool sum = 0;

			for (ll k = n - 1; k >= 0; k--)
			{
				sum |= L[i+n-k-1][j+n-k-1][k];
				// cout <<L[i][j][k]<<endl;
				if(sum)break;
			}
			// cout << endl;
			if (sum == 0) ans++;
		}
	}
	cout << ans << endl;
}
