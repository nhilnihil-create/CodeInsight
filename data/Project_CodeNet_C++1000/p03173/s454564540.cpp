#include<bits/stdc++.h>
#define REP(i, a, b) for(long long i=a; i<=b; ++i)
#define REPN(i, a, b) for(long long i=a; i<=b; --i)
#define rep(i, a, b) for(long long i=a; i<b; ++i)
#define rep0(i,b) for(long long i=0; i<b; ++i)
#define REP0(i,b) for(long long i=0; i<=b; ++i)
#include<cmath>
#include <iomanip>
using namespace std;


typedef long long ll;

int MODE = 1e9+7;

int main()
{

    int n;
    cin>>n;
    ll dp[n][n];
    memset(dp, -1, sizeof(dp));
    ll arr[n];
    rep0(i, n)
    {
        cin>>arr[i];
    }
    ll prefix[n+1];
    prefix[0] = 0;
    rep0(i, n+1)
    {
        prefix[i] = prefix[i-1] + arr[i];
    }
    for(int i=0; i<n; ++i)
    {
        dp[i][i] = 0;
    }

    for(int i=n-2; i>=0; --i)
    {

        for(int j=i+1; j<n; ++j)
        {
            dp[i][j] = 1e18+5;
            ll s =  prefix[j] - prefix[i-1];           
            for(int k = i; k<j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + s);
            }
        }
    }

    cout<<dp[0][n-1]<<endl;



    return 0;

}
