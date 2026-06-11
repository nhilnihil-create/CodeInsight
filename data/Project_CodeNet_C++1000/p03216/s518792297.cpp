#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1000010
#define LL long long
char a[N];
int b[N],t1[N],t2[N];
LL s1[N],s2[N];
int main()
{
    int i,j,k,n,m;
    int x,y,z,d;
    LL s,ans;
    scanf("%d%s",&n,a+1);
    s1[0]=0;
    s2[0]=0;
    t1[0]=0;
    t2[0]=0;
    k=0;
    for(i=1;i<=n;i++)
    {
        s1[i]=s1[i-1];
        s2[i]=s2[i-1];
        t1[i]=t1[i-1];
        t2[i]=t2[i-1];
        if(a[i]=='M')
        {
            t1[i]++;
            s1[i]++;
        }
        else
        if(a[i]=='D')
            b[k++]=i;
        else
        if(a[i]=='C')
        {
            t2[i]++;
            s2[i]=s2[i]+s1[i];
        }
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&d);
        ans=0;
        for(i=0;i<k;i++)
        {
            j=min(b[i]+d-1,n);
            s=max((LL)0,s2[j]-s2[b[i]]-((LL)t1[b[i]]*(t2[j]-t2[b[i]])));
            ans=ans+s;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
