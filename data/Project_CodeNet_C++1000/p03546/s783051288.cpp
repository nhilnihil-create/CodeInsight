//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void warshall_floyd(vector<vector<int>>& d, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


void solve() {
    int H, W; cin >> H >> W;
    vector<vector<int>> c(10, vector<int>(10));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }

    warshall_floyd(c, 10);

    int cost = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a; cin >> a;
            if (a == -1) continue;
            cost += c[a][1];
        }
    }

    cout << cost << endl;
}


int main() {
    solve();
    return 0;
}