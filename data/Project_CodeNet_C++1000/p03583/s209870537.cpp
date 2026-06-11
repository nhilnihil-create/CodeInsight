#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n; cin>>n;
	for(ll a=1;a<=3500;a++){
		for(ll b=1;b<=3500;b++){
			ll x=a+b;
			ll y=a*b;
			ll p=y*n;
			ll q=(4*y)-(x*n);
			if(q<=0) continue;
			if(p%q) continue;
			ll c=p/q;
			if(c>3500) continue;
			cout<<a<<" "<< b<<" "<<c<<endl;
			return 0;
		}
	}	
	return 0;
}