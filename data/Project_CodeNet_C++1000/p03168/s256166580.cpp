#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
signed main()
{
    SPEED;
    int n;
    cin>>n;
    double p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    double dp[n+2]={0},res=0;
    dp[0]=(1.00-p[0]);
    dp[1]=p[0];
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(dp[j]>0)
            {
                dp[j+1]=(double)dp[j]*(1.00*p[i])+(double)dp[j+1]*(1.00-p[i]);
            }
        }
        dp[0]*=(1.00-p[i]);
    }
    for(int i=n/2;i<n;i++)
    res+=dp[i+1];
    cout<<fixed<<setprecision(10)<<res;
}