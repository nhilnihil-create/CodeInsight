#include<bits/stdc++.h>
const int N = 1e5+1e2;
#define ll long long 
const int mod = 1e9+7;
int n;
ll a[N],ans;
ll inv[N],sum[N]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	inv[1]=1;
	ll f=1;
	for(int i=2;i<=n;++i)
		inv[i]=(1ll*(mod-mod/i)*inv[mod%i])%mod;
	for(int i=1;i<=n;++i)
		sum[i]=(sum[i-1]+inv[i])%mod,f=(1ll*f*i)%mod;
	for(int i=1;i<=n;++i)
		ans=(1ll*ans+a[i]*(sum[i]+sum[n-i+1]-1))%mod;
	printf("%lld\n",(ans*f)%mod);
	return 0;
}