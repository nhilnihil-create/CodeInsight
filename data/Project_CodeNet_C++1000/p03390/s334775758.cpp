#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long ll;
int q,a,b,ans;

inline ll calc_sqrt(ll n){
	ll l=0,r=sqrt(n)+100;
	while(l<r){
		ll mid=l+r+1>>1;
		if(mid*mid<=n)
			l=mid;
		else
			r=mid-1;
	}
	return l;
}

int main(){
	cin>>q;
	while(q--){
		cin>>a>>b;
		if(a==1&&b==1){
			cout<<0<<endl;
			continue;
		}
		ll n=(ll)a*b-1,x=calc_sqrt(n);
		if(n/x==x)
			ans=2*x-1;
		else
			ans=2*x;
		if(a<=x)
			--ans;
		else if(n/a&&x-n/a>=n/(n/a)-x)
			--ans;
		if(b<=x)
			--ans;
		else if(n/b&&x-n/b>=n/(n/b)-x)
			--ans;
		cout<<ans<<endl;
	}
	return 0;
}