#include <iostream>
#define mod 1000000007
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    char grid[h+1][w+1];
    int dp[h+1][w+1];
    for (size_t i = 0 ; i <= h; i++) {
        grid[i][0] = '.';
        dp[i][0] = 0;
    }
    for (size_t i = 0 ; i <= w; i++) {
        grid[0][i] = '.';
        dp[0][i] = 0;
    }
    dp[1][0] = 1;
    for (size_t i = 1 ; i <= h; i++) {
        for (size_t j = 1 ; j <= w; j++) {
            cin>>grid[i][j];
        }
    }
    for (size_t i = 1 ; i <= h; i++) {
        for (size_t j = 1 ; j <= w; j++) {
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            } else dp[i][j] = 0;
        }
    }
    std::cout << dp[h][w] << endl;
}
