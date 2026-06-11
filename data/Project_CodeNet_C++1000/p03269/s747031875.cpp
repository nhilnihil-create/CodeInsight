#include<iostream>
#include<cstdio>
using namespace std;
const int N=20005;
long long n,k,w,k1,t,cnt,p,p1[N],kl[N],l[N],r[N],v[N];
int main()
{
    scanf("%d",&n);
    k=1;
    if(n==1)
    {
        printf("2 1\n1 2 0\n");
        return 0;
    }
    t=1;
    while(t*2<=n)
    {
        l[++cnt]=k;
        r[cnt]=k+1;
        v[cnt]=0;
        l[++cnt]=k;
        r[cnt]=k+1;
        v[cnt]=t;
        k++;
        t=t*2;
    }
    k1=k;
    n=n-t;
    w=t;
    while(n>0)
    {
        t=1;
        k=1;
        while(t*2<=n) 
            t=t*2,k++;
        l[++cnt]=k;
        r[cnt]=k1;
        v[cnt]=w;
        w=w+t;
        n=n-t;
    }
    printf("%d %d\n",k1,cnt);
    for(int i=1;i<=cnt;i++)
        printf("%d %d %d\n",l[i],r[i],v[i]);
    return 0;
}