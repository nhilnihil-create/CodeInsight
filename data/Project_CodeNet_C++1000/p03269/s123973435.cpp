#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;

int L,n,m,bin[N],a[N];
struct data{int x,y,w;}ans[N];

void add(int x,int y,int w)
{
    m++;
    ans[m].x=x;ans[m].y=y;ans[m].w=w;
}

int main()
{
    scanf("%d",&L);
    n=20;
    bin[0]=1;
    for (int i=1;i<=20;i++) bin[i]=bin[i-1]*2;
    for (int i=n-1;i>=2;i--) add(i,i+1,bin[n-i-1]),add(i,i+1,0);
    int top=0,sum=0;
    while (L>=262144) add(1,2,sum),sum+=262144,L-=262144;
    while (L) a[++top]=L%2,L/=2;
    for (int i=top;i>=1;i--)
    {
        if (!a[i]) continue;
        add(1,n-i+1,sum);
        sum+=bin[i-1];
    }
    printf("%d %d\n",n,m);
    for (int i=1;i<=m;i++) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].w);
    return 0;
}