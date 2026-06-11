/**
 *    author:  FromDihPout
 *    created: 2020-08-10
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    const int N = 10;
    int h, w;
    cin >> h >> w;
    vector<vector<int>> c(N, vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
        }
    }
    
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int x;
            cin >> x;
            if (x != -1) ans += c[x][1];
        }
    }
    cout << ans << '\n';
    return 0;
}