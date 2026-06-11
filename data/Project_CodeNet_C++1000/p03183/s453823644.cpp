#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main()
{
	ll n;
	cin >> n;
	ll w[n], s[n], v[n], wmax=0, w1[n], s1[n], v1[n];
	vector <pair<ll, ll> > weights, temp;
	for(ll i = 0; i < n; i++)
	{
		cin >> w[i] >> s[i] >> v[i];
		if(w[i] + s[i] > wmax)
			wmax = w[i] + s[i];
		temp.push_back(make_pair(s[i]+w[i], i));
	}
	sort(temp.begin(), temp.end());
	for(ll i = 0; i < n; i++)
	{
		w1[i] = w[temp[i].second];
		s1[i] = s[temp[i].second];
		v1[i] = v[temp[i].second];
	}
	ll ans[n][wmax+1], check[n][wmax+1];
	for(ll i = 0; i < wmax+1; i++)
	{
		if(i>=w1[0])
		{
			ans[0][i] = v1[0];
		}
		else
		{
			ans[0][i] = 0;
		}
	}
	for(ll i = 1; i < n; i++)
	{
		ans[i][0] = 0;
		for(ll j = 1; j<wmax+1; j++)
		{
			if(j-w1[i]<=s1[i] && j-w1[i]>=0)
				ans[i][j] = max(ans[i-1][j], ans[i-1][j-w1[i]]+v1[i]);
			else if(j-w1[i] < 0)
				ans[i][j] = ans[i-1][j];
			else
				ans[i][j] = max(ans[i-1][j], ans[i-1][s1[i]] + v1[i]);
		}
	}
	cout << ans[n-1][wmax];
}