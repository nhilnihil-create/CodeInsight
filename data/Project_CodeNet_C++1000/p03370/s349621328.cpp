#include<bits/stdc++.h>
#define ll long long int 
#define w(x) int x; cin>>x; while(x--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n,x;
	cin>>n>>x;
	ll a[n];
	ll s=0;
	ll c=0;
	for(ll i=0; i<n; i++){
		cin>>a[i];
		s+=a[i];
	}
	c=n;
	x-=s;
	sort(a,a+n);
	c+=x/a[0];
	cout<<c;
}