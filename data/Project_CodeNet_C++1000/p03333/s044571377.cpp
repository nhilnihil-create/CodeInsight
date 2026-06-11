#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int n,t1,t2;
struct node
{
    int x,id;
}a[N],b[N];
bool cmp1(node a,node b)
{
    return a.x>b.x;
}
bool cmp2(node a,node b)
{
    return a.x<b.x;
}
bool vis[N];
int disa(int x,int y)
{
    return max(y-x,0);
}
int disb(int x,int y)
{
    return max(x-y,0);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&b[i].x);
        a[i].id=b[i].id=i;
    }
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+n,cmp2);
    int now=0;
    ll ans=0;
    t1=t2=1;
    for(int i=1;i<=n;i++)
    {
        while(t1<=n&&vis[a[t1].id]) t1++;
        while(t2<=n&&vis[b[t2].id]) t2++;
        if(i&1)
        {
            ans+=disa(now,a[t1].x);
            if(disa(now,a[t1].x)) now=a[t1].x;
            vis[a[t1].id]=true;
        }
        else
        {
            ans+=disb(now,b[t2].x);
            if(disb(now,b[t2].x)) now=b[t2].x;
            vis[b[t2].id]=true;
        }
    }
    ans+=abs(now);
    ll res=0;
    memset(vis,false,sizeof(vis));
    t1=t2=1;
    now=0;
    for(int i=1;i<=n;i++)
    {
        while(t1<=n&&vis[a[t1].id]) t1++;
        while(t2<=n&&vis[b[t2].id]) t2++;
        if((i&1)^1)
        {
            res+=disa(now,a[t1].x);
            if(disa(now,a[t1].x)) now=a[t1].x;
            vis[a[t1].id]=true;
        }
        else
        {
            res+=disb(now,b[t2].x);
            if(disb(now,b[t2].x)) now=b[t2].x;
            vis[b[t2].id]=true;
        }
    }
    res+=abs(now);
    printf("%lld\n",max(ans,res));
}
