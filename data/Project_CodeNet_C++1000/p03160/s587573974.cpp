#include <iostream>
#include <algorithm>
#include <queue>

#define rep(i,n) for (int i=0; i < (n); ++i)
using ll = long long ;
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;

int dp[110000] ;

int main() {

    int n ;
    cin >> n ;
    int h[n+1];
    rep(i,n) cin >> h[i] ;
    dp[0] = 0 ;

    for(int i=1;i<n;i++){
        if(i==1)dp[i-1] + abs(h[i]-h[i-1]) ;
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]),
                    dp[i-2] + abs(h[i]-h[i-2])) ;
    }
    cout << dp[n-1] << endl ;
    return 0 ;
}