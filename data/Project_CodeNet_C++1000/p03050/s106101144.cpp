#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll n;
	cin>>n;
	ll x=sqrt(n);
	ll ans=0;
	for(int i=1;i<=x;i++){
		if(n%i==0){
			if(n/i<i-1)ans+=i-1;
			ll p=n/i;
			if(n/p<p-1)ans+=p-1;
		}
	}
	cout<<ans;
	return 0;
}
