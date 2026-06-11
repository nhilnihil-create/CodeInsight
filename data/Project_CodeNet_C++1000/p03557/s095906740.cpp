#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n),b(n),c(n);
	for(ll i=0;i<n;i++)
		cin>>a[i];
	for(ll i=0;i<n;i++)
		cin>>b[i];
	for(ll i=0;i<n;i++)
		cin>>c[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		vector<ll>::iterator lower,upper;
    	lower = lower_bound (a.begin(), a.end(),b[i]);  
    	upper = upper_bound (c.begin(), c.end(),b[i]);
		ans+=(lower-a.begin())*(n-(upper-c.begin()));
	
	}
	cout<<ans;
	return 0;
}