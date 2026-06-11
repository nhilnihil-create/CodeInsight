#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	string s,t;
	cin >> s;
	ll n = s.size();
	for(ll i = 0;i<n;i++)
	{
		if(s[i]=='B'&&s[i+1]=='C')t.push_back('D'),i++;
		else
		{
			t.push_back(s[i]);
		}
	}
	n = t.size();
	ll cnt = 0;
	ll ans = 0;
	for(auto c:t)
	{
		if(c=='A')
		{
			cnt++;
		}
		else if(c=='D')
		{
			ans += cnt;
		}
		else
		{
			cnt = 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}