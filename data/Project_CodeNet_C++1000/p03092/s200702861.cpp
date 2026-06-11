#include<bits/stdc++.h>
using namespace std;
#define MN 5000
#define ll long long
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
ll f[MN+5],A,B;
int n;
int main()
{
    n=read();A=read();B=read();
    memset(f,63,sizeof(f));f[0]=0;
    for(int i=1;i<=n;++i)
    {
        int x=read();
        for(int j=0;j<x;++j)
        {
            f[x]=min(f[x],f[j]);
            f[j]+=A;
        }
        for(int j=x;++j<=n;) f[j]+=B;
    }
    ll ans=1e18;
    for(int i=0;i<=n;++i) ans=min(ans,f[i]);
    cout<<ans;
    return 0;
}