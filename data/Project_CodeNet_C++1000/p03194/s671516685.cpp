#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll n,p;
	cin >> n >> p;
	map <ll,ll> m;
	for(ll i = 2 ; i*i <= p ; i++)
	{
		while(p % i == 0)
		{
			m[i]++;
			p /= i;
		}
	}
	if(p > 1)
		m[p]++;
	ll ans = 1;
	for(auto i = m.begin() ; i != m.end() ; i++)
	{
		ans *= pow(i->first,(i->second/n));
	}
	cout << ans;
}