#include<bits/stdc++.h>
#define ll long long int
#define f first
#define s second
#define pb push_back
#define PII pair<ll,ll>
ll const MOD = 1000000007;
ll const N = 1000005;
ll const LN = 20;
ll const inf = 8e18;
using namespace std;

ll n, m, a[N];
vector<ll>v[N];
vector<ll>ok;
int main()
{
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	string str;
	cin >> str;
	ll n = str.size();
	str = " " + str;
	if (str[1] == '0' || str[n] == '1')
	{
		cout << "-1";
		return 0;
	}
	ll past = n - 1;
	for (ll i = 1; i < n; i++)
	{
		if (str[i] != str[past])
		{
			cout << "-1";
			return 0;
		}
		past--;
	}
	for (ll i = 2; i <= n; i++)
	{
		ok.pb (i);
	}
	ll ver = 1;
	for (ll i = 1; i < n; i++)
	{
		if (str[i] == '1')
		{
			ll oo = ok.back();
			ok.pop_back();
			v[oo].pb (ver);
			v[ver].pb (oo);
			ver = oo;
		}
		else
		{
			ll oo = ok.back();
			ok.pop_back();
			v[ver].pb (oo);
			v[oo].pb (ver);
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		for (auto w : v[i])
		{
			if (w > i)
			{
				cout << w << " " << i << '\n';
			}
		}
	}
	return 0;
}
