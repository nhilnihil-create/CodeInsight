/**
 *    author:  FromDihPout
 *    created: 2020-08-17
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c, vector<int> (c)), a(n, vector<int> (n));
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> cols(3, vector<int> (c));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int m = ((i + 1) + (j + 1)) % 3;
            cols[m][a[i][j] - 1]++;
        }
    }
    
    int ans = 1e9;
    for (int c1 = 0; c1 < c; c1++) {
        for (int c2 = 0; c2 < c; c2++) {
            if (c1 == c2) continue;
            for (int c3 = 0; c3 < c; c3++) {
                if (c1 == c3 || c2 == c3) continue;
                int cost = 0;
                for (int i = 0; i < c; i++) {
                    cost += cols[0][i] * d[i][c1];
                    cost += cols[1][i] * d[i][c2];
                    cost += cols[2][i] * d[i][c3];
                }
                ans = min(ans, cost);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}