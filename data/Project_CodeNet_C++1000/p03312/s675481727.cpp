#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N];
ll sum1[N],sum2[N];
ll solve(int l1,int r1,int l2,int r2)
{
    if(l1<=0||l1>=r1||l2<=0||l2>=r2) return 1e18;
    //cout<<sum1[r1]<<' '<<sum1[l1]<<' '<<sum2[r2]<<' '<<sum2[l2]<<endl;
    return max(max(sum1[r1]-sum1[l1],sum1[l1]),max(sum2[r2]-sum2[l2],sum2[l2]))-min(min(sum1[r1]-sum1[l1],sum1[l1]),min(sum2[r2]-sum2[l2],sum2[l2]));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum1[i]=sum1[i-1]+a[i],sum2[i]=a[i];
    reverse(sum2+1,sum2+1+n);
    for(int i=1;i<=n;i++) sum2[i]+=sum2[i-1];
    ll ans=1e18;
    for(int i=2;i<=n-2;i++)
    {
        int m=n-i;
        int pos1=lower_bound(sum1+1,sum1+1+i,sum1[i]/2)-sum1;
        int pos2=lower_bound(sum2+1,sum2+1+m,sum2[m]/2)-sum2;
        for(int j=pos1-1;j<=pos1+1;j++)
            for(int k=pos2-1;k<=pos2+1;k++)
            ans=min(ans,solve(j,i,k,m));
    }
    printf("%lld\n",ans);
}
