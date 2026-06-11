#include <bits/stdc++.h>
using namespace std;

void warshall_floyd(const int n,
                    vector<vector<int64_t>>& cost) {
    // 辺が存在しない場合は(1LL << 60)で初期化する
    for (auto i = 0; i < n; i++) cost[i][i] = 0;
    for (auto k = 0; k < n; k++) {
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                // 直接行く場合とkを経由する場合でより小さい距離を採用する
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int64_t>> cost(10, vector<int64_t>(10));
    for (auto i = 0; i < 10; i++) for (auto j = 0; j < 10; j++) cin >> cost[i][j];
    warshall_floyd(10, cost);
    int64_t ans = 0;
    for (auto i = 0; i < h; i++) {
        for (auto j = 0; j < w; j++) {
            int a; cin >> a;
            if(a == -1) continue;
            ans += cost[a][1];
        }
    }
    cout << ans << endl;
    return 0;
}