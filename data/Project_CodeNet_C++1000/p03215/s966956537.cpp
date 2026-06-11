#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n),b;
	for(auto &i:a)cin >> i;
	for(ll i = 0;i<n;i++)
	{
		ll now = 0;
		for(ll j = i;j<n;j++)
		{
			now += a[j];
			//cout<<bitset<8>(now)<<endl;
			b.push_back(now);
		}
	}
	sort(b.rbegin(),b.rend());
	for(ll i = 60;i>=0;i--)
	{
		ll cnt = 0;
		vector<ll> c;
		for(ll j = 0;j<b.size();j++)
		{
			if((b[j]>>i)&1)c.push_back(b[j]);
		}
		
		if(c.size()>=k)
		{
			b=c;
		}
	}
	for(ll i = 1;i<b.size();i++)
	{
		b[0]&=b[i];
	}
	cout<<b[0]<<endl;
}