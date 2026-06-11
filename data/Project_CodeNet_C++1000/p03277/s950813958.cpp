
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
const int maxm=2e5;
ll c[maxn*2+10];
int a[maxn+10];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int val)
{
    for(int i=x;i<=maxm;i+=lowbit(i))
    {
        c[i]+=val;
    }
}
ll sum(int x)
{
    ll ret=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        ret+=c[i];
    }
    return ret;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int l=0,r=1e9;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int cc=0;
            ll ret=0;
            for(int i=0;i<=maxm;i++)
                c[i]=0;
            add(n+1,1);
            for(int i=1;i<=n;i++)
            {
                cc+=a[i]>=mid?1:-1;
                ret+=sum(cc+n+1);
                add(cc+n+1,1);
            }
            if(ret >= (ll)n*(n+1)/2 - ret)
            {
                l=mid+1;
                ans=mid;
            }
            else
            {
                r=mid-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}