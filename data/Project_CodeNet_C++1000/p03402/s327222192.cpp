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
int A,B;
char mp[110][110];
signed main()
{
    A=read(), B=read();
    puts("100 100");
    for(ri int i=1;i<=50;i++)for(ri int j=1;j<=100;j++)mp[i][j]='.';
    for(ri int i=51;i<=100;i++)for(ri int j=1;j<=100;j++)mp[i][j]='#';
    for(ri int i=1;i<=50;i++, i++)
    for(ri int j=1;j<=100&&B>1;j++, j++)
    mp[i][j]='#', B--;
    for(ri int i=100;i>50;i--, i--)
    for(ri int j=100;j&&A>1; j--, j--)
    mp[i][j]='.', A--;
    for(ri int i=1;i<=100;i++,puts(""))
    for(ri int j=1;j<=100;j++) printf("%c",mp[i][j]);
    return 0;
}