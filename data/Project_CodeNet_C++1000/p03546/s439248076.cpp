#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    int h, w; cin >> h >> w;
    const int n = 10;
    vector<vector<int>> d(n, vector<int>(n));    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    for (int k = 0; k < n; k++) {       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // k を経由する場合と経由しない場合を(すべてのkについて)比較
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int a; cin >> a;
            if (a == -1) continue;
            ans += d[a][1];
        }
    }
    cout << ans << endl;
    return 0;
}