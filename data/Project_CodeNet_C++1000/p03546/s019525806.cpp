// 5/29
// 2-5-5 わーシャルフロイド
// 類題
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

// 二頂点間の距離を格納する隣接行列
vector<vector<int>> dist;

void warshall_floyed(int N) {
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int H, W;
    cin >> H >> W;

    dist.assign(10, vector<int>(10, INF));
    rep(i, 10) {
        rep(j, 10) {
            int c;
            cin >> c;
            dist[i][j] = c;
        }
    }

    warshall_floyed(10);

    int ans = 0;

    // map<int, int> mp;
    rep(i, H) {
        rep(j, W) {
            int a;
            cin >> a;

            if (a != -1) {
                // mp[a]++;
                ans += dist[a][1];
            }
        }
    }

    // for (auto p : mp) {
    //     ans += dist[p.first][1] * p.second;
    // }

    cout << ans << endl;
}
