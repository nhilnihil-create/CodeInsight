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
ll dp[3005][3005];
int main()
{
    char s[3005],t[3005];
    scs(s);
    scs(t);
    ll sz=strlen(s);
    ll tz=strlen(t);
    FOR(i,0,sz)
    {
        dp[tz][i]=0;
    }
    FOR(i,0,tz)
    {
        dp[i][sz]=0;
    }
    FORr(i,sz-1,0)
    {
        FORr(j,tz-1,0)
        {
            if(s[i]==t[j])
                dp[i][j]=dp[i+1][j+1]+1;
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    ll index=dp[0][0];
    char arr[index+1];
    arr[index]='\0';
    index=0;
    ll i=0,j=0;
    while(i<sz&&j<tz)
    {
        if(s[i]==t[j])
        {
            arr[index]=s[i];
            index++;
            i++;
            j++;
        }
        else if(dp[i+1][j]>dp[i][j+1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    //cout<<
    pts(arr);
    return 0;
}
