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

    int n,k;
    cin>>n>>k;
    ll arr[n+1];
    arr[0] = -1;
    rep0(i, n)
    {
        cin>>arr[i+1];
    }





    int dp[n+1][k+1];

    rep0(i, n+1)
    {
        dp[i][0] = 1;
    }
   // cout<<dp[0][0]<<endl;

    rep0(i, k+1)
    {
        dp[0][i] = 0;
    }
     dp[0][0] = 1;


    rep(i, 1,n+1)
    {
        vector<ll> prefixSum(k+1);
        prefixSum[0] = 1;
        rep(j, 1, k+1)
        {
            prefixSum[j] = (prefixSum[j-1]+dp[i-1][j] + MODE)%MODE ;
        }
        rep(j, 1, k+1)
        {
            if(j<=arr[i])
            {
                dp[i][j] = prefixSum[j];
            }
            else
            {
                dp[i][j] = (prefixSum[j] - prefixSum[j - arr[i] - 1] + MODE)%MODE;
            }
        }

    }

    //rep0(i, n+1)
    //{
      //  rep0(j, k+1)
        //{
          //  cout<<dp[i][j]<<"\t";
        //}
        //cout<<endl;
    //}

    cout<<dp[n][k]%MODE<<endl;


    return 0;

}
