#include<bits/stdc++.h>
#define ll long long
#define RE register
#define R read()
using namespace std;
inline ll read()
{
    ll x=0,k=1;char c=getchar();
    while (c<'0' || c>'9') {if (c=='-') k=-1;c=getchar();}
    while (c>='0' && c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*k;
}
bitset<2000010> f;ll a[2011],n,sum;
int main()
{
    n=R;for(RE int i=1;i<=n;++i) a[i]=R,sum+=a[i];
    f[0]=1;for(RE int i=n;i>=1;--i)f|=f<<a[i];
    for(RE int i=(sum+1)>>1;i<=sum;++i)if(f[i]){printf("%d\n",i);return 0;}
}