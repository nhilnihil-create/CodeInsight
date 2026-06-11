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
#define ff(a,n) for(ll i=a;i<n;i++)
int main()
{
	ll n; cin>>n; ll a[n];
	ff(0,n) cin>>a[i];
	ll d=*min_element(a,a+n);
	ll x=d;
	while(1)
	{
		ff(0,n) if(a[i]%d!=0) d=a[i]%d;
		if(d==x) break;
		if(d==1) break;
		x=d;	
	}
	cout<<d;
}