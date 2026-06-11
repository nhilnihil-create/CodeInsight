#include <bits/stdc++.h>
using namespace std;

// ワーシャルフロイド法
// 頂点が制限された状態での最短コスト(最短経路)を計算し、dp で記録、負のコストでも解ける O(n^3)
// 参考資料：https://qiita.com/ageprocpp/items/cdf67e828e1b09316f6e#%E3%83%AF%E3%83%BC%E3%82%B7%E3%83%A3%E3%83%AB%E3%83%95%E3%83%AD%E3%82%A4%E3%83%89%E6%B3%95

#define INF 2147483647
#define KNUM 10

int main() {
    // マス目の大きさ入力
    int nHeight, nWidth;
    cin >> nHeight >> nWidth;
    // 魔力入力
    vector<vector<int>> cost(KNUM, vector<int>(KNUM));
    for (int i = 0; i < KNUM; i++){
        for (int j = 0; j < KNUM; j++){    
            cin >> cost.at(i).at(j);
        }
    }
    // マス目に書かれた数字の情報
    vector<vector<int>> a(nHeight, vector<int>(nWidth));
    for (int i = 0; i < nHeight; i++){
        for (int j = 0; j < nWidth; j++){    
            cin >> a.at(i).at(j);
        }
    }
    
    // 魔力の最小値を調べる
    vector<vector<int>> dp(KNUM, vector<int>(KNUM, INF));
    for (int k = 0; k < KNUM; k++){
        dp[k][k] = min(dp[k][k], cost[k][k]);
        for (int i = 0; i < KNUM; i++){
            dp[i][k] = min(dp[i][k], cost[i][k]);
            for (int j = 0; j < KNUM; j++){
                dp[k][j] = min(dp[k][j], cost[k][j]);
                if (dp[i][k] != INF && dp[k][j] != INF){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }        
    }

    int costSum = 0; 
    for (int i = 0; i < nHeight; i++){
        for (int j = 0; j < nWidth; j++){
            if (a[i][j] != -1){
                costSum += dp[a[i][j]][1];
            }
        }
    }

    cout << costSum << endl;

    return 0;
}
