#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

bool C(ll X,ll A,ll B){
	for(ll i=max(1LL,X/2-3);i<=min(X+1,X/2+3);i++){
		if(X<A&&i==X+1)break;
		if(i==A)continue;
		ll c=i-(A<=i);
		ll j=X+(B<=X)+1-c;
		if(B<=X&&j<=B)j--;
		if(i*j>=A*B)return 0;
	}
	return 1;
}
int main(){
	int q;cin>>q;
	rep(i,q){
		ll a,b;scanf("%lld%lld",&a,&b);
		if(a>b)swap(a,b);
		ll l=0,r=INT_MAX;
		while(r-l>1){
			ll t=(l+r)/2;
			if(C(t,a,b))l=t;
			else r=t;
		}
		printf("%lld\n",l);
	}
}