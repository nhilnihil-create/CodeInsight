#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define t ll t;cin>>t;while(t--)
#define nn cout<<endl;
int main()
{
	ll n;
	cin>>n;
	ll a[n+1],b[n+1];
	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++)
	{
		ll x; cin>>x;
		b[i]=a[i]-x;
	}
	ll y=0;
	for(ll i=0;i<n;i++)
	{
		if(b[i]>=0) y+=b[i];
	}
	cout<<y<<endl;
}