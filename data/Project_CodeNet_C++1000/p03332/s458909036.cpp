#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod = 998244353;
const int MAXN = 3e5 + 10;
int n,a,b,k,fac[MAXN],inv[MAXN];
inline int Pow(int a, int b,int ans=1) {
    for(;b;b>>=1,a=a*a%Mod) if(b&1) ans=ans*a%Mod;
    return ans;
}
inline void init() {
    fac[0]=1;
    for(int i=1;i<MAXN;i++) {
        fac[i]=(fac[i-1]*i)%Mod;
    }
    inv[MAXN-1]=Pow(fac[MAXN-1],Mod-2);
    for(int i=MAXN-2;i>=0;i--) {
        inv[i]=inv[i+1]*(i+1)%Mod;
    }
}
inline int C(int n,int m) {
    if(n<m) return 0;
    return fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
signed main() {
    cin>>n>>a>>b>>k;
    int ans=0;
    init();
    for (int i = 0; i <= n; i++) {
        if(a*i>k) break;
        if((k-a*i)%b) continue;
        int cnt=(k-a*i)/b;
        if(cnt>n) continue;
        ans=(ans+C(n,i)%Mod*C(n,cnt)%Mod+Mod)%Mod;
    }
    cout<<ans<<endl;
    return 0;
}