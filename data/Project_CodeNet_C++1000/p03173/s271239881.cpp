#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
long long n,i,d,k;
long long dp[405][405];
long long s[405];
long long a[405];
long long sum(int l, int r)
{
    return s[r]-s[l-1];
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];

    for(d=1;d<n;d++)
    {
        for(i=1;i+d<=n;i++)
        {
            dp[i][i+d]=1e18;
            for(k=i;k<i+d;k++)
                dp[i][i+d]=min(dp[i][i+d], dp[i][k]+dp[k+1][i+d]);

            dp[i][i+d]+=sum(i, i+d);
        }
    }

    cout<<dp[1][n];
    return 0;
}
