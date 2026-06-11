#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define MAX 105
#define int long long int
using namespace std;
double dp[3005][3005];

int32_t main()
{
    int n;
    cin>>n;
    double p[n];
    for(int i=0; i<n; i++)
        cin>>p[i];
    dp[0][0] = 1.0;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j)
                dp[i][j]+=p[i-1]*dp[i-1][j-1];
            dp[i][j]+=(1-p[i-1])*(dp[i-1][j]);
        }
    }
    double ans = 0;
    for(int i=0; i<=n; i++)
        if(i>n-i)
            ans+=dp[n][i];
    printf("%.12f\n", ans);
    return 0;
}
