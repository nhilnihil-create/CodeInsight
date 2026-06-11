#include <iostream>
#define mod 1000000007

using namespace std;
long long n,len,i,lo,hi,now,ans;
long long dp[3005][3005];
long long sum[3005];
string s;
int main()
{
    cin>>n;
    cin>>s;
    dp[1][1]=1;
    for(len=2;len<=n;len++)
    {
        for(i=1;i<len;i++)
            sum[i] = (sum[i-1]+dp[len-1][i])%mod;
        for(now=1;now<=len;now++)
        {
            if(s[len-2]=='<')
            {
                lo=1;
                hi=now-1;
            }
            else
            {
                lo=now;
                hi=len-1;
            }
            if(lo>hi)
                continue;
            dp[len][now]+=sum[hi]-sum[lo-1];
            if(dp[len][now]<0)
                dp[len][now]+=mod;
            dp[len][now]%=mod;
            /*
            for(last=lo;last<=hi;last++)
            {
                dp[len][now]+=dp[len-1][last];
                dp[len][now]%=mod;
            }
            */

        }
    }
    for(i=1;i<=n;i++)
    {
        ans+=dp[n][i];
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
