#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll x=5;
	vector<ll> a(x);
	
	for(int i=0;i<x;i++)
		cin>>a[i];
	ll k;
  	cin>>k;
  	if(a[4]-a[0]>k)
      	cout<<":(";
  	else
      	cout<<"Yay!";
  
	return 0;
}
