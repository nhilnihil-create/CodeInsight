#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
using i64 = int64_t;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep2(i, x, n) for(int i=x;i<n;++i)

int main()
{   
    int n,z,w;
    cin >> n >> z >> w;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int dp[n+1][2][n+1]; //[remain][turn][card_id]
    rep(i,n+1) rep(j,2) rep(k,n+1) dp[i][j][k] = 0;
    rep(j,2)
        rep(k,n+1)
        {
            int a_opp = k==0 ? (j==0 ? w : z) : a[k-1];
            dp[1][j][k] = abs(a[n-1]-a_opp);
        }

    rep2(i,2,n+1)
        rep(k,n+1)
        {
            dp[i][0][k] = max(dp[i-1][0][k],dp[i-1][1][n-i+1]);
            dp[i][1][k] = min(dp[i-1][1][k],dp[i-1][0][n-i+1]);  
        }

    cout << dp[n][0][0] << endl;
    return 0;
}