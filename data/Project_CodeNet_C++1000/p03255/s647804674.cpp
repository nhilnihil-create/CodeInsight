#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N];
ll x,sum[N];
int main()
{
    scanf("%d%lld",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    ll ans=sum[n]*5+2*n*x;
    for(int i=1;i<=n;i++)
    {
        ll res=x*i;
        for(int j=n,t=1;j>=1;j-=i,t++)
        {
            res+=(sum[j]-sum[max(0,j-i)])*(t==1?5:2*t+1);
            if(res>ans) break;
        }
        ans=min(ans,res);
    }
    printf("%lld\n",ans+n*x);
}
