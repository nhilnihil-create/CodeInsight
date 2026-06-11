#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=3e5+10;
const LL p=998244353;
LL n,a,b,k;
LL fac[N],inv[N];
inline LL pw(LL x,LL y){
	LL ans=1;
	while(y){
		if(y&1)(ans*=x)%=p;
		x=x*x%p; y>>=1;
	}
	return ans;
}
inline LL C(LL n,LL m){
	return m>n?0:fac[n]*inv[m]%p*inv[n-m]%p;
}
int main(){
	fac[0]=inv[0]=1;
	for(int i=1; i<N; ++i)fac[i]=fac[i-1]*i%p,inv[i]=pw(fac[i],p-2);
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	LL ans=0;
	for(LL i=0; i<=n; ++i){
		LL j=(k-a*i)/b;
		if(a*i+b*j==k&&j>=0)ans=(ans+C(n,i)*C(n,j)%p)%p;
	}
	printf("%lld",ans);
	return 0;
}