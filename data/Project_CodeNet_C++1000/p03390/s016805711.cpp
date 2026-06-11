#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll get_sqrt(ll x){
	ll l=1,r=1e9+10,mid,ans;
	while(l<=r){
		mid=l+r>>1;
		if(mid*mid<=x) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll a,b,n;
		scanf("%lld%lld",&a,&b);
		if(a>b) swap(a,b);
		n=a*b-1;
		ll g=get_sqrt(n),ans=0;
		ans=g+g;
		if(a<=g) ans--;
		if(g*(g+1)>n) ans--;
		printf("%lld\n",ans);
	}
	return 0;
}