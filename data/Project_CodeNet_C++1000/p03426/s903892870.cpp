#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<long long>> A(H, vector<long long>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    vector<int> x(H*W), y(H * W);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            x[A[i][j]] = i;
            y[A[i][j]] = j;
        }
    }
    vector<long long> dp(H * W, -1);
    for(int i = 0; i < H * W; i++){
        if(dp[i] != -1) continue;
        if(i < D && dp[i] == -1) dp[i] = 0;
        else{
            dp[i] = dp[i - D] + abs(x[i] - x[i - D]) + abs(y[i]- y[i - D]);
        }
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        cout << dp[R] - dp[L] << endl;
    }
}