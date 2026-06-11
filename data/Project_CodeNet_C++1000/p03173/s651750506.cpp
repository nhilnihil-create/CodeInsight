#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll slimes(ll arr[], int n){

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for(int i=1; i<=n; i++)
        prefix[i] = prefix[i-1] + arr[i-1];

    for(int l=2; l<=n; l++){
        for(int i=0; i<=n-l; i++){
            int j = i+l-1;
            ll minCost = 1LL<<60;
            for(int p=i; p<j; p++){
                ll currCost = dp[i][p] + dp[p+1][j] +
                              (prefix[p+1]-prefix[i]) +
                              (prefix[j+1]-prefix[p+1]);
                if(currCost < minCost)
                    minCost = currCost;
            }
            dp[i][j] = minCost;
        }
    }
    return dp[0][n-1];
}

int main()
{
 int n;
 cin>>n;
 ll arr[n];
 for(int i=0; i<n; i++)
     cin>>arr[i];
 ll ans = slimes(arr, n);
 cout<<ans;
 return 0;
}

