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
	vector<ll> a(n+1),pre(n+2),suf(n+2);
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=gcd(pre[i-1],a[i]);
	}
	ll ans=1;
	for(ll i=n;i>=1;i--)
	{
		suf[i]=gcd(suf[i+1],a[i]);
	}
	for(ll i=1;i<=n;i++)
	{
		ans=max(ans,gcd(pre[i-1],suf[i+1]));
	}
	cout<<ans;
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
