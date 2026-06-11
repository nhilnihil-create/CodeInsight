#include<cstdio>
#include<cctype>
#include<algorithm>
typedef long long int64;
inline int64 getint() {
    register char ch;
    while(!isdigit(ch=getchar()));
    register int64 x=ch^'0';
    while(isdigit(ch=getchar())) x=(((x<<2)+x)<<1)+(ch^'0');
    return x;
}
const int N=3e5+1,mod=998244353;
int fac[N],ifac[N];
void exgcd(const int &a,const int &b,int &x,int &y) {
    if(!b) {
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
inline int inv(const int &x) {
    int ret,tmp;
    exgcd(x,mod,ret,tmp);
    return (ret%mod+mod)%mod;
}
inline int power(int a,int k) {
    int ret=1;
    for(;k;k>>=1) {
        if(k&1) ret=(int64)ret*a%mod;
        a=(int64)a*a%mod;
    }
    return ret;
}
inline int C(const int &n,const int &m) {
    return (int64)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main() {
    int n=getint(),a=getint(),b=getint();
    int64 k=getint();
    for(register int i=fac[0]=1;i<=n;i++) {
        fac[i]=(int64)fac[i-1]*i%mod;
    }
    ifac[n]=inv(fac[n]);
    for(register int i=n;i>=1;i--) {
        ifac[i-1]=(int64)ifac[i]*i%mod;
    }
    int ans=0;
    for(register int i=0;i<=n&&(int64)a*i<=k;i++) {
        if((k-(int64)a*i)%b!=0) continue;
        const int64 j=(k-(int64)a*i)/b;
        if(j>n) continue;
        (ans+=(int64)C(n,i)*C(n,j)%mod)%=mod;
    }
    printf("%d\n",ans);
    return 0;
}