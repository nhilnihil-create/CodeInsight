#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int v[100005];
int main()
{
    int n,ans1=0,ans11=0,ans2=0,ans22=0,t1=0,t2=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
    {
        if(i&1)
        {
            a[v[i]]++;
            if(a[v[i]]>ans1) ans1=a[v[i]],t1=v[i];
        }
        else
        {
            b[v[i]]++;
            if(b[v[i]]>ans2) ans2=b[v[i]],t2=v[i];
        }
    }
    int ans;
    if(t2==t1)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
        {
            if(v[i]==t2) continue;
            if(i&1)
            {
                a[v[i]]++;
                if(a[v[i]]>ans11) ans11=a[v[i]];
            }
            else
            {
                b[v[i]]++;
                if(b[v[i]]>ans22) ans22=b[v[i]];
            }
        }
        ans=max(ans1+ans22,ans2+ans11);
        ans=n-ans;
    }
    else ans=n-ans1-ans2;
    printf("%d\n",ans);
}
