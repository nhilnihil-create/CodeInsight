#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0; i<n; i++)
		cin>>a[i];
	ll gcd=a[0];
	for(ll i=0; i<n; i++){
		ll x=max(gcd,a[i]);
		ll y=min(gcd,a[i]);
		while(y!=0){
			ll temp=y;
			y=x%y;
			x=temp;
		}
		gcd=x;
		if(gcd==1)
			break;
	}
	cout<<gcd<<endl;


}