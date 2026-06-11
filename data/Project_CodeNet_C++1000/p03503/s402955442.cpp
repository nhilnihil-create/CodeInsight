/**
 *    author:  FromDihPout
 *    created: 2020-08-10
**/

#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    const int DAYS = 10;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> p(n, vector<int> (DAYS + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < DAYS; j++) {
            int x;
            cin >> x;
            a[i] *= 2;
            a[i] += x;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < DAYS + 1; j++) {
            cin >> p[i][j];
        }
    }
    
    int ans = -INF;
    for (int open = 1; open < 1<<DAYS; open++) {
        int profit = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int d = 0; d < DAYS; d++) {
                if ((1<<d) & open & a[i]) {
                    cnt++;
                }
            }
            profit += p[i][cnt];
        }
        ans = max(ans, profit);
    }
    cout << ans << '\n';
    return 0;
}