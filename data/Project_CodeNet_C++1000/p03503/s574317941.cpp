#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    int n; cin >> n;
    const int q = 10;
    vector<vector<int>> f(n, vector<int>(q));
    vector<vector<int>> p(n, vector<int>(q+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            cin >> f[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q + 1; j++) {
            cin >> p[i][j];
        }
    }
    int ans = -1000000000;
    for (int bit = 1; bit < (1 << q); ++bit) {
        vector<int> timeCnt(n, 0);
        int profit = 0;
        for (int j = 0; j < q; ++j) {
            if (bit & (1 << j)) {
                for (int i = 0; i < n; i++) {
                    if (f[i][j] == 1) timeCnt[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            profit += p[i][timeCnt[i]];
        }
        ans = max(ans, profit);
    }
    cout << ans << endl;
    return 0;
}