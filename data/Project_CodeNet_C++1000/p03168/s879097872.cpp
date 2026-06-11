// https://atcoder.jp/contests/dp/tasks/dp_i

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define precision(x,d) cout<<fixed<<setprecision(d)<<x

int main()
{
    int n;
    cin >> n;
    long double a[n];
    for(int i=0 ; i<n ; i++)
        cin >> a[i];

    long double dp[n][n+1];

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ;j<=n ; j++)
            dp[i][j] = 0.0;
    }

    dp[0][0] = 1-a[0];
    dp[0][1] = a[0];

    for(int i=1 ; i<n ; i++)
        dp[i][0] = dp[i-1][0]*(1-a[i]);

    for(int i=1 ;i<n ;i++)
    {
        for(int j=1 ;j<=n ; j++)
                dp[i][j] = dp[i-1][j]*(1-a[i]) + dp[i-1][j-1]*a[i];
    }
    /*for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<=n ; j++)
          cout << dp[i][j] << " ";
        cout << endl;
    }*/
    long double ans = 0.0;
    for(int i=(n/2+1) ; i<=n ; i++)
        ans += dp[n-1][i];
    precision(ans,13);
    return 0;
}
