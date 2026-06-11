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

const int maxn=2e5+7;
LL a[maxn];
int n;
LL x;
int main()
{
    n=read();x=read();
    for(int i=1;i<=n;i++)a[i]=read()+a[i-1];
    LL ans=1e18;
    for(int k=1;k<=n;k++){
        LL now=3,res=0;
        for(int i=n;i>=1;i-=k){
            res+=(a[i]-a[max(0,i-k)])*max(now,5LL);now+=2;
            if(res>=ans)break;
        }
        res+=1LL*(k+n)*x;
        if(res<ans)ans=res;
    }
    printf("%lld\n",ans);
    return 0;
}
