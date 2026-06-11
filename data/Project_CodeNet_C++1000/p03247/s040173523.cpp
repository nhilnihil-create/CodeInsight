#include <bits/stdc++.h>
#define N 1007
using namespace std;
int n,x[N],y[N];
long long a[40],l[40],r[40];
int main(){
    scanf("%d",&n);
    int flag=-1;
    for(int i=1;i<=n;++i){
        scanf("%d%d",&x[i],&y[i]);
        int t=abs(x[i])+abs(y[i]);
        if(flag==-1)flag=t%2;
        else if(t%2!=flag){puts("-1");return 0;}
    }
    if(!flag)printf("40\n1 ");
    else puts("39");
    for(int i=0;i<39;++i){
        cout<<(1LL<<i);
        if(i<38)putchar(' ');
        else puts("");
    }
    for(int i=1;i<=n;++i){
        if(!flag)
            if(x[i]<0)putchar('R'),--x[i];
            else putchar('L'),++x[i];
        long long t=abs(x[i])+abs(y[i]);
        a[39]=1LL<<38;
        for(int j=38;j;--j)
            if(t&(1LL<<j))a[j]=1LL<<(j-1);
            else a[j]=-(1LL<<(j-1));
        long long s=0;
        if(x[i]){
            for(int j=1;j<40;++j){
                l[j]=min(l[j-1]+a[j],l[j-1]);
                r[j]=max(r[j-1]+a[j],r[j-1]);
            }
            t=abs(x[i]);
            for(int j=39;j;--j)
                if(t>=l[j-1]+a[j] && t<=r[j-1]+a[j])s|=1LL<<j,t-=a[j];
        }
        for(int j=1;j<40;++j)
            if(s&(1LL<<j))
                if((x[i]<0)^(a[j]<0))putchar('L');
                else putchar('R');
            else
                if((y[i]<0)^(a[j]<0))putchar('D');
                else putchar('U');
        puts("");
    }
}
