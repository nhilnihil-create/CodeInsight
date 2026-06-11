#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<queue>
#include<map>
#include<math.h>
#include<climits>

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
ll n,a[100005],b[100005],c[100005],dp[100010][3],op0,op1,op2;
int main()
{
    scl(n);
    FOR(i,1,n)
    {
        scl(a[i]);
        scl(b[i]);
        scl(c[i]);
    }
    dp[n][0]=a[n];
    dp[n][1]=b[n];
    dp[n][2]=c[n];
    FORr(i,n-1,1)
    {
        if(i+1<=n)
        {
            op0=dp[i+1][0];
            op1=dp[i+1][1];
            op2=dp[i+1][2];
        }
        else
        {
            op0=LONG_MIN;
            op1=LONG_MIN;
            op2=LONG_MIN;
        }
        dp[i][0]=max(op1+a[i],op2+a[i]);
        dp[i][1]=max(op0+b[i],op2+b[i]);
        dp[i][2]=max(op0+c[i],op1+c[i]);
       // cout<<dp[i][0]<<endl;
    }
    ll ans=max(dp[1][0],dp[1][1]);
    ans=max(ans,dp[1][2]);
    ptl(ans);
    return 0;
}
