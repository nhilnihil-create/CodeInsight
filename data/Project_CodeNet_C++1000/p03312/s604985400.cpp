#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=2e5+5;
const int maxm=5e2+5;
const int maxq=55;
const int INF=0x3f3f3f3f;
ll sum[maxn];
ll gs(ll l,ll r)
{
    return sum[r]-sum[l-1];
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int x;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum[i]=sum[i-1]+x;
        }
        ll l=1;ll r=3;
        ll ans=-1;
        for(int i=2;i<=n-2;i++)
        {
            while(l+1<i&&abs(gs(1,l)-gs(l+1,i))>=abs(gs(1,l+1)-gs(l+2,i))) l++;
            while(r+1<n&&abs(gs(i+1,r)-gs(r+1,n))>=abs(gs(i+1,r+1)-gs(r+2,n))) r++;

            ll mx=max(gs(1,l),max(gs(l+1,i),max(gs(i+1,r),gs(r+1,n))));
            ll mn=min(gs(1,l),min(gs(l+1,i),min(gs(i+1,r),gs(r+1,n))));
            if(ans==-1) ans=mx-mn;
            else ans=min(ans,mx-mn);
        }
        printf("%lld\n",ans);
    }
}
