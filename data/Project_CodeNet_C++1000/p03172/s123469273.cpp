#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int mod = 1e9 + 7;
#define int long long int

int32_t main() {
    IOS ;
    // int t ; cin >> t ; while(t--) {}
    
    int n, k ; cin >> n >> k ; 
    int arr[n+1], dp[n+1][k+1] ;  
    
    for(int i=1; i<=n; i++) cin >> arr[i] ; 
    
    dp[0][0] = 1 ;
    for(int i=1; i<=k; i++) dp[0][i] = 0 ; 
    for(int i=1; i<=n; i++) dp[i][0] = 1 ;
    
    for(int i=1; i<=n; i++) {
        
        int sum[k+1] ; sum[0] = dp[i-1][0] ; 
        for(int j=1; j<=k; j++) 
        sum[j] = (sum[j-1] + dp[i-1][j]) % mod ;
        
        for(int j=1; j<=k; j++)
        if(j - arr[i] - 1 >= 0) 
        dp[i][j] = (sum[j] - sum[j-arr[i]-1]+ mod) % mod ; 
        else dp[i][j] = sum[j] ;
    }
    
    cout << dp[n][k] ; 
    
    return 0 ;
}
