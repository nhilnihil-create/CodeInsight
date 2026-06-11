#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=3000005;

int n,a,b,ans[N];

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    if (a==1)
    {
        if (b!=n) {puts("-1");return 0;}
        for (int i=n;i>=1;i--) printf("%d ",i);
        return 0;
    }
    if (a>n||b>n) {puts("-1");return 0;}
    int tot=0,now=b;
    for (int i=b;i>=1;i--) ans[++tot]=i;
    if (n-b<a-1) {puts("-1");return 0;}
    int x=(n-b)/(a-1),y=(n-b)%(a-1);
    if (x+(y>0)>b) {puts("-1");return 0;}
    for (int i=1;i<=y;i++)
    {
        for (int j=now+x+1;j>now;j--) ans[++tot]=j;
        now+=x+1;
    }
    for (int i=1;i<=a-1-y;i++)
    {
        for (int j=now+x;j>now;j--) ans[++tot]=j;
        now+=x;
    }
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}