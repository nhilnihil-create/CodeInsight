#define _USE_MATH_DEFINES //M_PI, M_E
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
ll power(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,h;
	cin>>n>>h;
	vector<ar<ll,2>> v;
	ll ans = 0;
	for(ll i = 0,j,k; i<n; i++){ cin>>j>>k; v.pb({j,k});}
	vector<ar<ll,2>> v2;
	for(ll i=0; i<n; i++) v2.pb({v[i][1],v[i][0]});
	sort(v2.begin(),v2.end(),greater<ar<ll,2>>());	
	sort(v.begin(),v.end(),greater<ar<ll,2>>());
	ll f = v[0][0];
	ll cnt = 0;
	for(int i = 0; i<n; i++)
		if(h>0 && v2[i][0]>f)
		{
			cnt++;
			h -= v2[i][0];
		}
	if(h<=0)cout<<cnt<<endl;
	else
	{
		cnt += (h/f);
		if(h%f!=0) cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}