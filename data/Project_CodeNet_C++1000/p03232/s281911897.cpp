    #include <bits/stdc++.h>
    using namespace std;
    const long long mod=1e9+7;
    int n;
    long long a[100010],inv[100010],pre[100010],ans,fac[100010];
    int main(){
    	scanf("%d",&n);
    	for(int i=1;i<=n;++i)
    	scanf("%lld",&a[i]);
    	inv[1]=1;
    	for(int i=2;i<=n;++i)
    	inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    	for(int i=1;i<=n;++i)
    	pre[i]=(pre[i-1]+inv[i])%mod;
    	for(int i=1;i<=n;++i)
    	ans=(ans+pre[n-i+1]*a[i]%mod+(pre[i]-1)*a[i]%mod)%mod;
    	fac[0]=1;
    	for(int i=1;i<=n;++i)
    	fac[i]=fac[i-1]*i%mod;
    	ans=(ans*fac[n])%mod;
    	printf("%lld\n",ans);
    }