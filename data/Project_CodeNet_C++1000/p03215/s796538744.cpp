#include <bits/stdc++.h>
#define mem(s,t) memset(s,t,sizeof(s))
#define pb(s) push_back(s)
#define inf 0x3f3f3f3f
#define mn 100010
typedef long long ll;
using namespace std;
vector<ll> p[50];
ll a[1010],sum[1010];
int n,k,now;
ll ans;

void work()
{
    ll pp=42,nowp;
    int i,j;
    while (pp>=0)
    {
        nowp=1ll<<pp;
        p[now+1].clear();
        for (i=0;i<p[now].size();i++)
            if ((p[now][i]&nowp)!=0) p[now+1].push_back(p[now][i]);
        if (p[now+1].size()>=k)
        {
            now++;
            ans+=nowp;
           // cout<<now<<' '<<nowp<<' '<<p[now].size()<<endl;
        }
        pp--;
    }
}

int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    p[0].clear();
    now=0;
    sum[0]=0;
    for (i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for (i=1;i<=n;i++)
        for (j=i;j<=n;j++)
            p[0].push_back(sum[j]-sum[i-1]);
    ans=0;
    work();
    printf("%lld\n",ans);
    return 0;
}

