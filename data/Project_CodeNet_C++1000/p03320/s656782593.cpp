#include<stdio.h>
typedef long long ll;
typedef double du;
const du inf=9223372036854775807.;
du S(ll n){
	du s=0;
	while(n){
		s+=n%10;
		n/=10;
	}
	return s;
}
ll f(ll n){
	ll d,t,f;
	du mn,s;
	f=n;
	mn=n/S(n);
	for(d=1;d<=n;d*=10){
		t=n/d*d+d*10-1;
		s=t/S(t);
		if(s<mn){
			mn=s;
			f=t;
		}
	}
	return f;
}
int main(){
	int k;
	ll n;
	scanf("%d",&k);
	for(n=1;k--;n=f(n+1))printf("%lld\n",n);
}