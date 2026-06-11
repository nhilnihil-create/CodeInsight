#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(void)
{
	ll n,s=0;
	cin>>n;
	ll c[n],v[n];
	for(ll i=0;i<n;i++)
	{
		cin>>c[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(ll i=0;i<n;i++)
	{
		if(c[i]-v[i]>0)
		{
			s+=(c[i]-v[i]);
		}
	}
	cout<<s<<endl;
}