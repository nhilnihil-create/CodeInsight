#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1e5+5;
const int mod=1e9+7;
int pow(int,int,int);
int fac[N],inv[N];
int a[N];
int f[N],dp[N];
int C(int n,int m){
    return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void init();
void work();
int ca=1;
int main(){
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    init();
//    int T;cin>>T;
//    while(T--)
    work();
    return 0;
}
void work(){
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++) fac[i]=1LL*fac[i-1]*i%mod;
    inv[N-1]=pow(fac[N-1],mod-2,mod);
    for(int i=N-2;i;i--) inv[i]=1LL*(i+1)*inv[i+1]%mod;

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=(f[i-1]+a[i])%mod;
    }
    dp[n]=f[n];
    for(int i=n-1;i;i--){
        dp[i]=(1LL*dp[i+1]+f[i]-f[n-i])%mod;
        if(dp[i]<0) dp[i]+=mod;
    }
    int ans=1LL*fac[n]*f[n]%mod;
    for(int i=1;i+2<=n;i++){
        dp[i]=(1LL*dp[i]-f[i]-(1LL*f[n]-f[n-i]))%mod;
        if(dp[i]<0) dp[i]+=mod;
        ans=(ans+2LL*dp[i]*fac[i]%mod*fac[n-i-2]%mod*C(n,i+2)%mod)%mod;
    }
    for(int i=1;i<n;i++){
        int t=(1LL*f[i]+f[n]-f[n-i])%mod;
        ans=(ans+1LL*t*fac[i]%mod*fac[n-i-1]%mod*C(n,i+1)%mod)%mod;
    }
    ans=(ans+mod)%mod;
    cout<<ans<<'\n';
}
int pow(int a,int p,int m){
    int re=1;
    for(;p;p>>=1){
        if(p&1) re=1LL*re*a%m;
        a=1LL*a*a%m;
    }
    return re;
}
