#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	ll n ;
	scanf("%lld",&n);
	map <ll , ll > cnt;
	vector<ll>v;
	v.push_back(0);
	for(int i = 0; i  < n ; i++)
	{
		ll input;
		scanf("%lld",&input);
		v.push_back(input);
	}
		sort(v.begin(),v.end());
	ll ans = 1e9;
	for(int i = 0;  i < v.size() ; i++)
	{
		if(i%2 == 0)
		{
			v[i] = 24-v[i];
		}
		if(v[i] == 24)
		{
			v[i] = 0;
		}
	}
	sort(v.begin(),v.end());
	for(int i = 0 ; i <v.size()-1 ; i++)
	{
		ans = min(abs(v[i]-v[i+1]) , ans);
	}
	cout<<ans<<endl;
	return 0;
}