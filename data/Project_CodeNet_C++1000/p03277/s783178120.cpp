#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+5;
const int maxm=5e2+5;
const int maxq=55;
const int INF=0x3f3f3f3f;
int a[maxn],mid,n;
int s[maxn*2];
int c[maxn*2];
int lowbit(int x)
{
    return x&(-x);
}
int query(int x)
{
    int sum=0;
    while(x)
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
void add(int x)
{
    while(x<maxn*2)
    {
        c[x]++;
        x+=lowbit(x);
    }
}
int check(int mid)
{
    memset(c,0,sizeof(c));
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+(a[i]>=mid?1:-1);
    }
    ll sum=0;
    for(int i=0;i<=n;i++)
    {
        sum+=query(s[i]+maxn);
        add(s[i]+maxn);
    }
    return sum*2>=1ll*n*(n+1)/2;
}
int main()
{
    while(~scanf("%d",&n))
    {
        int l=0;int r=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            r=max(r,a[i]);
        }
        int ans=0;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(check(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
}
