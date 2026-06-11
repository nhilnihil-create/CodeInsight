#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt" , "r" , stdin);
// 	freopen("output.txt" , "w" , stdout);
// #endif

	ll n, m, mx = INT_MIN;
	cin >> n >> m;
	ll a[n][3];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for (ll i = 0; i < 8; i++)
	{
		vector<ll>v;
		for (ll j = 0; j < n; j++)
		{
			ll s = 0;
			for (ll k = 0; k < 3; k++)
			{
				if ((i / (1 << k)) % 2 == 0)
				{
					s += a[j][k];
				}
				else
				{
					s -= a[j][k];
				}
			}
			v.push_back(s);
		}
		sort(v.begin(), v.end(), greater<ll>());
		ll sum = 0;
		for (ll i = 0; i < m; i++)
			sum += v[i];
		mx = max(mx, sum);

	}
	cout << mx << endl;



}
