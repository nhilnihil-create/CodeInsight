#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1e9+7;

void solve()
{

	ll n;
	cin>>n;
	ll a[5];
	for(ll i=0;i<5;i++)
	{
		cin>>a[i];
	}
	sort(a,a+5);
	ll x;
	if(a[0]>=n)
	{
		cout<<5;
		return;
	}
	// cout<<a[0];
	if(n%a[0]!=0)
		x=(n/a[0])+1;
	else
		x=n/a[0];
	// cout<<x<<endl;
	cout<<x+4;
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
