#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int main() {
    int H,W;
    cin >> H >> W;

    vector<vector<int>> c(10, vector<int>(10, INF));
    vector<vector<int>> A(H, vector<int>(W, 0));

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // ワーシャルフロイド法におけるiからjまで数字を変えるときの最小コストdp[k][i][j]
    vector<vector<int>> dp(10, vector<int>(10, INF));

    // 初期条件
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            dp[i][j] = c[i][j];
        }
    }

    // dp開始
    for(int k = 0; k < 10; k++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int count = 0;

    // 全ての数字に対して1に変えるのに必要なコストを求めて合計する
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j] != -1) {
                count += dp[A[i][j]][1];   
            }
        }
    }

    cout << count << endl;
	return 0;
}