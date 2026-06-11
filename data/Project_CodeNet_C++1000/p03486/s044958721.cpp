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
char s[N],t[N];
signed main()
{
    scanf("%s%s",s,t);
    int n=strlen(s), m=strlen(t);
    sort(s,s+n), sort(t,t+m);
    if(s[0]<t[m-1]) puts("Yes");
    else if(s[0]>t[m-1]) puts("Yes");
    else
    {
        if(s[0]==s[n-1]&&t[0]==t[m-1]&&s[0]==t[0])
        {
            if(m>n) puts("Yes");
            else puts("No");
            return 0;
        }
        int qwq=0;
        for(ri int i=0;i<n;i++)
        for(ri int j=0;j<m;j++)
        {
            if(t[j]>s[i]) { qwq++; break; }
        }
        if(qwq==n) puts("Yes");
        else puts("No");
    }
    return 0;
}