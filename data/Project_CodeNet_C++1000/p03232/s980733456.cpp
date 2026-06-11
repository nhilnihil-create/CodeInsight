#include<bits/stdc++.h>
#define read(x) scanf("%lld",&x)
using namespace std;
const int maxn=1e5+5;
typedef long long LL;
LL n,m;
const LL mod=1e9+7;
LL inv[maxn];
LL a[maxn];
LL sum[maxn];
void INV() {
    inv[1]=1;
    for(int i=2;i<=n;i++) {
        inv[i]=1LL*(mod-mod/i)*(inv[mod%i])%mod;
    }
}
int main() {
    read(n);
    INV();
    for(int i=1;i<=n;i++) {
        read(a[i]);
    }
    for(int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+inv[i];
        sum[i]%=mod;
    }
    LL ji=1;
    for(int i=1;i<=n;i++) {
        ji*=i;
        ji%=mod;
    }
    LL ans=0;
    for(int i=1;i<=n;i++) {
        ans+=((sum[i]-1)*a[i])%mod+(sum[n-i+1]*a[i])%mod;
        ans%=mod;
    }
    ans*=ji;
    ans%=mod;
    printf("%lld\n",ans);
}
