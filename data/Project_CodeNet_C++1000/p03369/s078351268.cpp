#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int ans;
signed main()
{
    char s[5];
    cin>>s;
    for(ri int i=0;i<3;i++) ans+=(s[i]=='o')*100;
    printf("%lld\n",ans+700);
    return 0;
}