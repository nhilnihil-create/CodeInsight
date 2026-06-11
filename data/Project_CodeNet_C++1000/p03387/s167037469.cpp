#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
signed main()
{
    int a[5];
    for(ri int i=0;i<3;i++) a[i]=read();
    sort(a,a+3);
    int qwq=1;
    for(ri int i=1;i<3;i++)
    {
        if((a[i]&1ll) != (a[i-1]&1ll)) qwq=0;
    }
    if(qwq)
    {
        int res=(a[1]-a[0])/2;
        res+=(a[2]-a[1]);
        printf("%lld\n",res);
    }
    else
    {
        int b[5];
        for(ri int i=0;i<3;i++) b[i]=(a[i]&1ll);
        int p,q; p=q=0;
        for(ri int i=0;i<3;i++) p+=b[i];
        q=3-p;
        if(p==2)
        {
            for(ri int i=0;i<3;i++) if(a[i]&1ll) a[i]++;
            sort(a,a+3);
            int res=(a[1]-a[0])/2;
            res+=(a[2]-a[1]);
            printf("%lld\n",res+1);
        }
        else
        {
            for(ri int i=0;i<3;i++) if(a[i]%2==0) a[i]++;
            sort(a,a+3);
            int res=(a[1]-a[0])/2;
            res+=(a[2]-a[1]);
            printf("%lld\n",res+1);
        }
    }
    return 0;
}