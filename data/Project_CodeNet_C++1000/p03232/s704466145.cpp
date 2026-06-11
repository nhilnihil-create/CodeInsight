#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const LL MOD=1e9+7;
LL qmod(LL a, LL b)
{
    if (b == 0) return 1;
    LL r = a % MOD;
    LL k = 1;
    while (b > 1){
        if ((b & 1)!=0)
            k = (k * r) % MOD;
        r = (r * r) % MOD;
        b >>= 1;
    }
    return (r * k) % MOD;
}

const int maxn=1e5+7;
int inv[maxn];

int main()
{
    int n=read();
    LL f=1;
    for(int i=1;i<=n;i++)f=(f*i)%MOD;
    for(int i=1;i<=n;i++)inv[i]=qmod(i,MOD-2);
    for(int i=1;i<=n;i++)inv[i]=(inv[i-1]+inv[i])%MOD;
    LL ans=0;
    for(int i=1;i<=n;i++){
        LL x=read();
        LL as=(x*((inv[i]+inv[n-i+1]-inv[1])%MOD))%MOD;
        ans=(ans+as)%MOD;
    }
    printf("%lld\n",(ans*f)%MOD);
    return 0;
}
