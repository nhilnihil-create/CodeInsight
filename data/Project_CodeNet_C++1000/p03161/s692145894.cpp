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

    int n,k ;
    cin >> n >> k ;
    int h[n];
    rep(i,n) cin >> h[i] ;
    dp[0] = 0 ;

    for(int i=1;i<n;i++){
        dp[i] = INF ;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
            dp[i] = min(dp[i],dp[i-j]+abs(h[i]-h[i-j])) ;
            }
        }
    }
    cout << dp[n-1] << endl ;
    return 0 ;
}