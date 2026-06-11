#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> dp(10, vector<int>(10, 10001));
    int c;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c;
            dp[i][j] = c;
        }
    }
    for (int i = 0; i < 10; i++) {
        dp[i][i] = 0;
    }
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int sum = 0, A;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A;
            if (A == -1) continue;
            sum += dp[A][1];
        }
    }
    cout << sum << endl;
}
