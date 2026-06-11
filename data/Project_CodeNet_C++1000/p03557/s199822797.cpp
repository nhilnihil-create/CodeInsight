#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	vector<ll> b(n);
	vector<ll> c(n);
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
		cin>>c[i];	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	ll ans = 0;
	for(int j=0;j<n;j++)
	{
		vector<ll>::iterator lower,higher;
		lower = lower_bound(a.begin(),a.end(),b[j]);
		ll i = lower - a.begin();
		higher = upper_bound(c.begin(),c.end(),b[j]);
		ll k = n - (higher - c.begin());
		ans += i*k;
	}
	cout<<ans;
	return 0;
}
