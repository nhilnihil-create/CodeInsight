#include <bits/stdc++.h>
using namespace std;
const int N = 1337;
const int MOD = 1e9+7;
char B[N][N];
int dp[N][N];
int main(){
    int h,w; cin >> h >> w;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> B[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(i-1 >= 1 && B[i-1][j] != '#'){
                dp[i][j] = (dp[i-1][j]+dp[i][j])%MOD;
            }
            if(j-1 >= 1 && B[i][j-1] != '#'){
                dp[i][j] = (dp[i][j-1]+dp[i][j])%MOD;
            }
        }
    }
    cout << dp[h][w];
}
