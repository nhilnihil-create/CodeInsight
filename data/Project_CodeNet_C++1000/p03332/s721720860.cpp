#include<bits/stdc++.h> 
#define rep(i,l,r) for (ll i=l;i<=r;i++)
#define per(i,l,r) for (ll i=l;i>=r;i--)
using namespace std;
typedef long long ll;
const ll mm=998244353;
const int N=300000;
ll fac[N+10],inv[N+10],ans,a,b,k,n;
ll Pow(ll x,ll y){
	ll ans=1;
	while (y){
		if (y&1) ans=ans*x%mm;
		x=x*x%mm;
		y/=2;
	}
	return ans;
}
ll C(ll n,ll m){
	if (n<m) return 0;
	return fac[n]*inv[m]%mm*inv[n-m]%mm;
}
int main(){
	fac[0]=1;
	rep(i,1,N) fac[i]=fac[i-1]*i%mm;
	inv[N]=Pow(fac[N],mm-2);
	per(i,N,1) inv[i-1]=inv[i]*i%mm;
	scanf("%lld",&n);
	scanf("%lld%lld%lld",&a,&b,&k);
	rep(y,0,n){
		ll res=b*y;
		if (k-res>=0&&(k-res)%a==0) {
			ll x=(k-res)/a;
			(ans+=C(n,x)*C(n,y)%mm)%=mm;
		}
	}
	printf("%lld\n",ans);
	return 0;
}