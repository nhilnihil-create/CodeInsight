#include <bits/stdc++.h>
#define LL long long 
#define N 100005     
#define setIO(s) freopen(s".in","r",stdin)     
using namespace std;
const LL mod=1000000007; 
LL a[N],n,inv[N],sum[N]; 
LL fac(int p) 
{
    LL ans=1ll; 
    for(int i=2;i<=n;++i) ans=ans*1ll*i%mod; 
    return ans; 
}
int main() 
{
    // setIO("input"); 
    int i,j; 
    scanf("%d",&n);
    for(i=1;i<=n;++i) scanf("%lld",&a[i]);  
    sum[1]=inv[1]=1ll; 
    for(i=2;i<=n;++i) 
    {
        inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod; 
        sum[i]=(sum[i-1]+inv[i])%mod;   
    }
    LL ans=0ll; 
    for(i=1;i<=n;++i) 
    {
        ans=(ans+a[i]*((sum[i]-sum[0]+sum[n-i+1]-sum[1]+mod)%mod)%mod)%mod; 
    }
    printf("%lld\n",ans*fac(n)%mod);   
    return 0; 
}