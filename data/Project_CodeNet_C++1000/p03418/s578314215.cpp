#include<bits/stdc++.h>
#define ll long long int
#define ar array
#define pb push_back
#define forf(i,a,b) for(i = a; i< b; i++)
#define forb(i,a,b) for(i = b; i>=a; i--)
using namespace std;
const int mod = 1e9+7;
ll power(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll ans = (n-k)*(n-k+1)/2;
	for(ll i = 1; i<=n; i++)
	{
		if(i==k || i<=k) continue;
		for(ll j = 1; j*i+k<=n;j++)
		{
			// cout<<ans<<endl;
			ll h = min((j+1)*i-1,n);
			ans += h-(i*j+k)+1;
			// cout<<ans<<endl;
		}
	}
	if(k==0) ans -= n;
	cout<<ans<<endl;
	return 0;
}