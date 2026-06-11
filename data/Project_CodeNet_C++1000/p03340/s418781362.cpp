#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline ll read()
{
    ll ret=0,flag=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')flag=-1;c=getchar();}
    while(c>='0'&&c<='9')ret=ret*10+(c^'0'),c=getchar();
    return flag*ret;
}

const ll N=2e5+5;
ll n;
ll s[N];
ll sum[N],_xor[N];
ll ans;

int main()
{
    n=read();
    for(ll i=1;i<=n;i++)s[i]=read();
    for(ll i=1;i<=n;i++)sum[i]=s[i]+sum[i-1],_xor[i]=s[i]^_xor[i-1];
    for(ll l=1,r=1;l<=n;)
    {
        while(r<n&&sum[r+1]-sum[l-1]==(_xor[r+1]^_xor[l-1]))
            r++;
        ans+=r-l+1;
        l++;
        if(r<l)r=l;
    }
    printf("%lld",ans);
    return 0;
}
