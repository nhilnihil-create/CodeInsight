#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=500010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
signed main()
{
    int x=read();
    int cnt=0;
    int p=x;
    while(x) cnt+=x%10, x/=10;
    if(p%cnt==0) puts("Yes");
    else puts("No");
    return 0;
}