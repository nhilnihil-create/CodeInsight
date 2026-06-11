#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
ll d[1000001]={1,0,1},f[1000001]={1},g[1000001]={1,1};
const ll p=998244353 ;
ll mul(ll a,ll b)
{
    ll res=0,mod=p;
    while(b>0)
    {
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}
LL comb(LL a,LL b){
	if(a==b)return 1;
	if(b<a)return 0;
	return mul(mul(f[b],g[a]),g[b-a]); 
} 
LL lucas(LL a,LL b){
	return b==0?1:lucas(a/p,b/p)*comb(a%p,b%p)%p;
}

main(){
	ll n,A,B,k,ans=0,sum=0;
	for(int i=1;i<=1000001;i++)
		f[i]=f[i-1]*i%p;
	for(int i=2;i<=1000001;i++)
		g[i]=(p-p/i)*g[p%i]%p;	
	for(int i=2;i<=1000001;i++)
		g[i]=g[i]*g[i-1]%p; 
	scanf("%lld%lld%lld%lld",&n,&A,&B,&k);
	for(int i=0;i<=n&&i*B<=k;i++){
		if((k-i*B)%A==0){
			sum+=mul(lucas((k-i*B)/A,n),lucas(i,n));
			sum%=p;
		}
	}
	printf("%lld\n",sum);
}