#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int N = 1e5 + 5;
#define int long long int

int32_t main() {
    IOS ;
    int n, k ; cin >> n ;
    if(n&1) k = n/2 ; 
    else k = n/2 - 1 ;

    double arr[n+1], dp[n+1][k+1] ;
    dp[0][0] = 1 ; 
    for(int i=1; i<n+1; i++) cin >> arr[i], dp[i][0] = arr[i]*dp[i-1][0] ; 

    // for(int i=0; i<=n; i++) cout << dp[i][0] << " ";

    for(int i=1; i<n+1; i++) arr[i] = 1 - arr[i] ;

    for(int i=0; i<n+1; i++) {
        for(int j=0; j<k+1; j++) {
            if(j == 0) continue ;
            else if(i == j) dp[i][j] = arr[i] * dp[i-1][j-1] ;
            else if(j > i) dp[i][j] = 0 ;
            else dp[i][j] = (arr[i] * dp[i-1][j-1]) + ((1-arr[i]) * dp[i-1][j]) ;   
        }
    }

    double res = 0 ;
    for(int i=0; i<=k; i++) res += dp[n][i] ;

    cout << std::setprecision(10) << res ;

    return 0 ;
}
