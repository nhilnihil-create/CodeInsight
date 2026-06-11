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
signed main()
{
    int a,b; string s;
    cin>>a>>b>>s;
    int n=s.length();
    int flg=0, pp=1;
    for(ri int i=0;i<n;i++)
    {
        if(i==a&&s[i]=='-') { flg=1; continue; }
        if(i!=a&&s[i]>='0'&&s[i]<='9'&&pp) pp=1;
        else if(i!=a) pp=0;
    }
    if(pp&&flg) puts("Yes");
    else puts("No");
    return 0;
}