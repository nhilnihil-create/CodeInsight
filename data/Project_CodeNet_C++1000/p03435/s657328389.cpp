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
int a[4][4];
signed main()
{
    for(ri int i=1;i<=3;i++)
    for(ri int j=1;j<=3;j++)
    a[i][j]=read();
    if(a[1][3]+a[3][1]==a[1][1]+a[3][3]
    &&a[1][2]+a[2][1]==a[1][1]+a[2][2]
    &&a[2][3]+a[3][1]==a[3][3]+a[2][1]
    &&a[3][2]+a[2][1]==a[3][1]+a[2][2]) puts("Yes");
    else puts("No");
    return 0;
}