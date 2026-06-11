#include <bits/stdc++.h>
using namespace std;

bool warshall_floyd(const int n,
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

    bool isNegativeCycle = false;
    for (auto i = 0; i < n; i++) {
        // 自身へのコストが0以下なら負の閉路がある
        if (cost[i][i] < 0) isNegativeCycle = true;
    }

    return isNegativeCycle;
}

int main(){
    int h, w;
    cin >> h >> w;

    const int COUNT = 10;

    vector<vector<int64_t>> magic(COUNT, vector<int64_t>(COUNT, 0));
    for (auto i = 0; i < COUNT; i++) {
        for (auto j = 0; j < COUNT; j++) cin >> magic[i][j];
    }

    map<int, int> number;
    for (auto i = 0; i < h; i++) {
        for (auto j = 0; j < w; j++) {
            int tmp; cin >> tmp;
            if(tmp >= 0) number[tmp]++;
        }
    }

    warshall_floyd(COUNT, magic);
    int64_t ans = 0;
    for (auto& elm : number) ans += magic[elm.first][1] * elm.second;

    cout << ans << endl;
    return 0;
}