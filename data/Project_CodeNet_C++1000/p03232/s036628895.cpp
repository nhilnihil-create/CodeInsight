#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,mod=1e9+7;
int n;
ll a[N],f[N],inv[N],sum[N];
int main()
{
    f[0]=f[1]=inv[0]=inv[1]=1;
    for(int i=2;i<N;i++) f[i]=f[i-1]*i%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<N-1;i++) sum[i]=(sum[i-1]+inv[i+1])%mod;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+a[i]*f[n]%mod*(sum[i-1]+sum[n-i]))%mod;
    for(int i=1;i<=n;i++) ans=(ans+a[i]*f[n])%mod;
    printf("%lld\n",ans);
}
