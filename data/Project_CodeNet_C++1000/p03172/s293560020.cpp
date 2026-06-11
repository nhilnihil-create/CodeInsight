#include<bits/stdc++.h>
using namespace std;
#define int long long


// time and space complexity = O(K*N)
int m = 1e9+7;

signed main(){
    
    int n,k;
    cin >> n >> k;
    vector<int> arr(n+1);
    // arr[i] = max candies ith child can take
    for(int i=1;i<=n;i++) cin >> arr[i];

    int dp[1+n][1+k];
    int sum[1+n][1+k];
    // dp[i][j] == number of ways of distributing j candies among first i children
    // sum[i][j] == sum of ith row of dp matrix from column 0 to j
    
    for(int j=0;j<=k;j++) {dp[0][j] = 0; sum[0][j]=1;}
    for(int i=0;i<=n;i++) {dp[i][0] = 1; sum[i][0]=1;}
    
    for(int child=1;child<=n;child++){
        for(int cand=1;cand<=k;cand++){
            int mx = arr[child];

            int mini = max(0LL, cand - mx);

            // BUG WAS HERE======================================================================
            dp[child][cand] = (sum[child-1][cand] - sum[child-1][mini] +m )%m + dp[child-1][mini];
            dp[child][cand] %= m;

            // sum update
            sum[child][cand] = dp[child][cand] + sum[child][cand-1];
            sum[child][cand] %= m;
        }
    }


    cout << dp[n][k] << endl;

    return 0;
}