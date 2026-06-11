#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7,MAX = 1e5;

int main()
{
	ll n;
	string s,t;
	cin >> s;
	n = s.size();
	s.push_back('A');
	for(ll i = 0;i<n;i++)
	{
		if(s[i]=='B'&&s[i+1]=='C')
		{
			t.push_back('D');
			i++;
		}
		else
		{
			if(i<n)t.push_back(s[i]);
		}		
	}
	ll m = t.size();

	ll cnta = 0,cntd = 0;
	ll ans = 0;
	for(ll i = 0;i<m;i++)
	{
		if(t[i]=='C'||t[i]=='B')
		{
			cnta = 0;cntd = 0;
		}
		else if(t[i]=='A')
		{
			cnta++;
		}
		else if(t[i]=='D')
		{
			ans += cnta;
		}
	}
	cout<<ans<<endl;
	return 0;
}