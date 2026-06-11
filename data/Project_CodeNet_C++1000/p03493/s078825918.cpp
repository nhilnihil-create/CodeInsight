#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
signed main()
{
    string s;
    cin>>s;
    int res=0;
    int n=s.length();
    for(ri int i=0;i<n;i++) res+=(s[i]=='1');
    printf("%lld\n",res);
    return 0;
}