#include <iostream>
#include <algorithm>
#include <queue>

#define rep(i,n) for (int i=0; i < (n); ++i)
using ll = long long ;
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;

int happy[110000][3] ;
int dp[110000][3] ;

//0 : umi
//1 : yama
//2 : ie

int main() {

    int n,k ;
    cin >> n  ;
    for(int i=1;i<=n;i++){
        cin >> happy[i][0] >> happy[i][1] >> happy[i][2] ;
    }    

    for(int i=1;i<=n;i++){
        for(int place=0;place<3;place++){
            for(int placeY = 0 ;placeY<3;placeY++){
                if(placeY==place) continue ;
                dp[i][place] = max(dp[i][place], dp[i-1][placeY] + happy[i][place]) ;
            }
        }
    }

    int ans = 0 ;
    for(int i=0;i<3;i++){
        ans = max(ans,dp[n][i]) ;
    }

    cout << ans << endl ;

    return 0 ;
}