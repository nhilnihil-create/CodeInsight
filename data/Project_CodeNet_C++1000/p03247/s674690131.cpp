#include<bits/stdc++.h>
#define maxn 1010
using namespace std;
template<typename T> inline void read(T &x)
{
    x=0;char c=getchar();bool flag=false;
    while(!isdigit(c)){if(c=='-')flag=true;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    if(flag)x=-x;
}
int n,cnt;
int x[maxn],y[maxn],d[maxn];
bool tag[2];
int main()
{
    read(n);
    for(int i=1;i<=n;++i)
        read(x[i]),read(y[i]),tag[((x[i]+y[i])%2+2)%2]=true;
    if(tag[0]&&tag[1])
    {
        puts("-1");
        return 0;
    }
    for(int i=30;i>=0;--i) d[++cnt]=(1<<i);
    if(tag[0]) d[++cnt]=1;
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;++i) printf("%d%c",d[i]," \n"[i==cnt]);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=cnt;++j)
        {
            if(abs(x[i])>abs(y[i]))
            {
                if(x[i]>0) x[i]-=d[j],putchar('R');
                else x[i]+=d[j],putchar('L');
            }
            else
            {
                if(y[i]>0) y[i]-=d[j],putchar('U');
                else y[i]+=d[j],putchar('D');
            }
        }
        putchar('\n');
    }
    return 0;
}