#include <bits/stdc++.h>
#define ll long long 
#define vi vector<int>
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pb push_back
#define f(i,a,b) for(i=a;i<b;i++)
using namespace std;

int main()
{
	int n,i,j,mx=1;
	
	cin>>n;
	int a[n],b[n+1],c[n+1];

	f(i,0,n)cin>>a[i];
	
	b[0]=a[0],c[0]=a[n-1];
	
	f(i,0,n)
	{
		b[i+1]=__gcd(a[i],b[i]);
	}
	f(i,0,n)c[i+1]=__gcd(c[i],a[n-1-i]);
	
	mx=max(b[n-1],c[n-1]);
	
	for(i=1;i<n-1;i++)
	{
		mx=max(mx,__gcd(b[i],c[n-i-1]));
	}
	cout<<mx;
}