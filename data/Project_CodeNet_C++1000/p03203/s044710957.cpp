#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
#define ll long long
#define N 200010
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
    int x=0,f=1;char c=getchar();
    while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
    while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
int r,c,n,t,x,y,ans;
map<int,int> f[N];
set<int> g[N];
struct data{int x,y;
}a[N];
int main()
{
    r=read(),c=read();n=read();ans=r+1;
    for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),f[a[i].x][a[i].y]=1,g[a[i].y].insert(a[i].x);
    for (int i=1;i<=c;i++) g[i].insert(r+1);
    int x=1,y=1;
    for (;x<r;)
    {
        ans=min(ans,*g[y].lower_bound(x));
        x++;if (!f[x][y+1]&&y<c) y++;
    }
    ans=min(ans,*g[y].lower_bound(x));
    cout<<ans-1;
    return 0;
}