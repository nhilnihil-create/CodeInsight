#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a[66];
char s[13];
signed main()
{
    n=read();
    for(ri int i=0;i<n;i++)
    {
        cin>>s;
        if(s[0]=='M') a[0]++;
        if(s[0]=='A') a[1]++;
        if(s[0]=='R') a[2]++;
        if(s[0]=='C') a[3]++;
        if(s[0]=='H') a[4]++;
    }
    int res=0;
    for(ri int i=0;i<5;i++)
    {
        for(ri int j=i+1;j<5;j++)
        {
            for(ri int k=j+1;k<5;k++) res+=a[i]*a[j]*a[k];
        }
    }
    printf("%lld\n",res);
    return 0;
}