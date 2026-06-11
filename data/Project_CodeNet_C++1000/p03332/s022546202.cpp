#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mo=998244353;
const int maxn=300007;

ll n,a,b,k,fac[maxn],inv[maxn]; 

ll C(int x,int y){
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}

int qpow(int x,int p){
	int rt=1;
	while(p){
		if(p&1)rt=(1ll*rt*x)%mo;
		x=(1ll*x*x)%mo;
		p>>=1;
	}
	return rt;
}
int res;
int main(){
	fac[0]=inv[0]=1;
	for(int i=1;i<maxn;++i){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=qpow(fac[i],mo-2);
	}
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	for(int i=0;i<=n&&i*a<=k;++i)
		if((k-i*a)%b==0&&n*b>=k-i*a)
			res=(res+1ll*C(n,i)*C(n,(k-i*a)/b)%mo)%mo;
	printf("%d\n",res);
	return 0;
}

