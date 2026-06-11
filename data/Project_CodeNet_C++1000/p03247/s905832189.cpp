#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int X,Y,x[1005],y[1005];
ll dis(int a,int b){return 1ll*abs(a-X)+abs(b-Y);}
int main()
{
    int n,t0=0,t1=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        if((x[i]+y[i])&1)t1=1;
        else t0=1;
    }
    if(t0&&t1){puts("-1");return 0;}
    printf("%d\n",31+t0);
    if(t0)printf("1 ");
    for(int i=30;i>=0;i--)printf("%d ",1<<i);
    puts("");
    for(int i=1;i<=n;i++)
    {
        if(t0)putchar('L'),x[i]++;
        int nx=0,ny=0;X=x[i],Y=y[i];
        for(int k=30;k>=0;k--)
        {
            ll d1=dis(nx+(1<<k),ny),d2=dis(nx-(1<<k),ny),
            d3=dis(nx,ny+(1<<k)),d4=dis(nx,ny-(1<<k)),mn=min(d1,min(d2,min(d3,d4)));
            if(mn==d1)putchar('R'),nx+=(1<<k);
            else if(mn==d2)putchar('L'),nx-=(1<<k);
            else if(mn==d3)putchar('U'),ny+=(1<<k);
            else putchar('D'),ny-=(1<<k);
        }
        puts("");
    }
    return 0;
}