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
#define m 1000000007
using namespace std;
ll dp[1005][1005];
int main()
{
    ll r,c;
    char ch[1005][1005];
    scl(r);
    scl(c);
    FOR(i,0,r-1)
    {
        scs(ch[i]);
    }
    dp[0][0]=1;
    FOR(i,1,c-1)
    {
        if(ch[0][i]!='#')
            dp[0][i]=dp[0][i-1];
        else
            dp[0][i]=0;
    }
    FOR(i,1,r-1)
    {
        if(ch[i][0]!='#')
            dp[i][0]=dp[i-1][0];
        else
            dp[i][0]=0;
    }
    ll op1,op2;
    FOR(i,1,r-1)
    {
        FOR(j,1,c-1)
        {
            if(ch[i][j]!='#')
                dp[i][j]=(dp[i][j-1]%m+dp[i-1][j]%m)%m;
            else
                dp[i][j]=0;
         //   cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    ptl(dp[r-1][c-1]);
    return 0;
}
