#include<bits/stdc++.h>
using namespace std;

const int N = 20004;
const int mod = 1000000007;
typedef long long  ll;

ll dp[N];
int n;

struct node
{
    int w,s,b;
};
bool cmp(node x,node y)
{
    return x.w+x.s<y.s+y.w;
}
node arr[N];


int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d %d %d",&arr[i].w,&arr[i].s,&arr[i].b);
    sort(arr+1,arr+n+1,cmp);
    dp[0]=0;
    for(int i=1; i<N; i++) dp[i]=-1e17;
    for(int i=1; i<=n; i++)
    {
        for(int j=arr[i].s; j>=0; j--)
        {
            dp[j+arr[i].w]=max(dp[j+arr[i].w],arr[i].b+dp[j]);
        }
    }
    ll ans=0;
    for(int i=0; i<N; i++) ans=max(ans,dp[i]);
    printf("%lld\n",ans);


}
