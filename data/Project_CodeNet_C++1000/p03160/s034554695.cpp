#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<queue>
#include<map>
#include<math.h>

#define FASTREAD      ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define ll long long
#define dd double
#define scl(n)        scanf("%lld",&n)
#define scd(n)        scanf("%lf",&n)
#define scc(n)        scanf("%c",&n)
#define scs(n)        scanf("%s",&n)
#define ptl(n)        printf("%lld",n)
#define ptd(n)        printf("%f",n)
#define ptc(n)        printf("%c",n)
#define pts(n)        printf("%s",n)
#define nline         printf("\n")
#define pb            push_back
#define FOR(i,a,b)    for(ll i=a;i<=b;i++)
#define FORr(i,a,b)   for(ll i=a;i>=b;i--)
#define pi            2*acos(0.0)
#define pii           pair<ll,ll>
#define uu            first
#define vv            second

using namespace std;

int main()
{
    ll n,h[100005],dp[100005];
    scl(n);
    FOR(i,1,n)
    {
        scl(h[i]);
    }
    dp[n]=0;
    dp[n-1]=abs(h[n-1]-h[n]);
    FORr(i,n-1,1)
    {
        if(i+2<=n){
        dp[i]=min(dp[i+1]+abs(h[i]-h[i+1]),dp[i+2]+abs(h[i]-h[i+2]));
      //  cout<<i<<" "<<dp[i]<<endl;
        }
    }
    ptl(dp[1]);
    nline;
    return 0;
}
