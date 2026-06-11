#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=1000010;
const int inf=2147483647;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*f;
}
int L,n=1,m=0,a[22],l=0;
struct Edge{int x,y,d;}e[70];
int main()
{
    L=read();
    int t=L-1;
    for(int i=0;(1<<i)<=t;i++)
    {
        n++;
        t-=(1<<i);
        e[++m].x=n-1,e[m].y=n,e[m].d=0;
        e[++m].x=n-1,e[m].y=n,e[m].d=(1<<i);
    }
    t=L;
    while(t)a[++l]=(t&1),t>>=1;
    int tot=(1<<(l-1));
    for(int i=l-1;i;i--)
    if(a[i])
    {
        e[++m].x=i,e[m].y=n,e[m].d=tot;
        tot+=(1<<(i-1));
    }
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++)printf("%d %d %d\n",e[i].x,e[i].y,e[i].d);
}