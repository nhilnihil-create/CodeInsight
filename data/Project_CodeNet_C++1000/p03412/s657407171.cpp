#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 2e5+100;
const LL mod = 998244353;
const LL INF=1e9;

int a[maxn],b[maxn],a1[maxn],b1[maxn];
int get_ans(int k,int n,int a[],int b[])
{
    int x=1<<k,y=1<<k+1;
    int z=x+y;
    LL cnt=0;
    int i1=n,i2=n,i3=n;
    for(int j=1;j<=n;j++)
    {
        //printf("j=%d ",j);
        while(i1>0&&b[j]>=x-a[i1])
        {
            cnt+=n-j+1;
            i1--;
            //printf("+%d ",n-j+1);
        }
        while(i2>0&&b[j]>=y-a[i2])
        {
            cnt-=n-j+1;
            i2--;
            //printf("-%d",n-j+1);
        }
        while(i3>0&&b[j]>=z-a[i3])
        {
            cnt+=n-j+1;
            i3--;
            //printf("*%d ",n-j+1);
        }
        //printf("\n");
    }
    //printf("k=%d cnt=%d\n",k,cnt);
    cnt=cnt&1;
    return cnt<<k;
}
int main()
{
    int n,i,j,k,x,y;
    int T;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    int ans=0;
    for(k=0;k<30;k++)
    {
        for(j=1;j<=n;j++)
        {
            a1[j]=a[j]&((1<<(k+1))-1);
            b1[j]=b[j]&((1<<(k+1))-1);
        }
        sort(a1+1,a1+1+n);
        sort(b1+1,b1+1+n);
        ans^=get_ans(k,n,a1,b1);
    }
    printf("%d\n",ans);
    return 0;
}

/**

*/
