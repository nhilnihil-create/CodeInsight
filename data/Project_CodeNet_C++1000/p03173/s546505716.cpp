#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NM=405;
const ll oo=1e18;

ll dp[NM][NM],s[NM];

int main()
{   int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
            dp[i][j]=oo;
    for(int i=1; i<=n; i++)
    {   ll x;
        cin>>x;
        s[i]=s[i-1]+x;
    }
    for(int i=1; i<=n; i++)
    {   dp[i][i]=0;
        dp[i][i+1]=s[i+1]-s[i-1];
    }
    /// dp[i][j]=costul minim pentru [i,j]
    for(int k=2; k<n; k++)
        for(int i=1,j; i+k<=n; i++)
        {   j=i+k;
            for(int l=i; l<j; l++)
                dp[i][j]=min(dp[i][j],dp[i][l]+dp[l+1][j]);
            dp[i][j]+=s[j]-s[i-1];
        }
    cout<<dp[1][n];
    return 0;
}