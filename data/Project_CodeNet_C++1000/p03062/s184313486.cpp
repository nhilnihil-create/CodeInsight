#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1e9+7;

ll f(pair<string,ll>&x ,pair<string,ll>&y) 
{
	if(x.first == y.first) 
	{
		return x.second>y.second;
	}
	else 
	{
		return x.first<y.first;
	}
}
 
void solve()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	ll sum=0,neg=0;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
			neg++;
		sum+=abs(a[i]);
		a[i]=abs(a[i]);
	}
	// cout<<sum;
	sort(a.begin(),a.end());
	// cout<<neg;
	// cout<<a[0];
	if(neg%2==1)
		sum-=(2*a[0]);
	cout<<sum;
	return;
}

int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}
