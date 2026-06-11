#include<bits/stdc++.h>
const int N=3e5+5,mo=998244353;
int vf[N],fac[N],inv[N];
inline int C(int n,int m){return 1ll*vf[m]*vf[n-m]%mo*fac[n]%mo;}
int n,a,b,i,ans;
long long k,x;
int main(){
	for(int i=*vf=*fac=1;i<N;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d%d%d%lld",&n,&a,&b,&k);
	for(i=0;i<=n && 1ll*i*a<=k;++i)if((k-1ll*i*a)%b==0){
		x=(k-1ll*i*a)/b;
		if(x<=n)ans=(ans+1ll*C(n,i)*C(n,x))%mo;
	}
	printf("%d\n",ans);
}