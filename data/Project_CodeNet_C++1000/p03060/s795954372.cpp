#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll n,sum=0;
	cin>>n;
	ll v[n],c[n];
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n;i++)
		cin>>c[i];
	for(int i=0;i<n;i++)
		sum+=max(0ll,v[i]-c[i]);
	cout<<sum;
	return 0;
}
