#include <bits/stdc++.h>
#define foi(i,n) for(int i = 0; i < n ; ++i)
#define pi pair<int,int>
#define mod 1000000007
using namespace std;

int dp[3005][3005];
// ith index , j daala
int solve(int n,string &arr){
    dp[n-1][1] = 1;
    for(int i = n-2;i>=0;i--){
        int bottom = n-i-1;
        for(int j = 1 ; j <= n-i ; j++){
            if(arr[i] == '<'){
                dp[i][j] = dp[i+1][j-1];
            }
            else{
                dp[i][j] = (dp[i+1][bottom] - dp[i+1][j-1]+mod)%mod;
            }
        }
        for(int j = 1 ; j<=n-i;j++) dp[i][j] = (dp[i][j]%mod +dp[i][j-1]%mod)%mod;
    }
    return dp[0][n];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    foi(i,3005){
        foi(j,3005) dp[i][j] = 0;
    }
    int n;
    cin >> n;
    string arr;
    cin >> arr;
    cout << solve(n,arr);
}
