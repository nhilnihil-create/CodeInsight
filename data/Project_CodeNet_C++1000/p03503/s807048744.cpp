#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> is_open(n, vector<int>(10));
    vector<vector<int>> profits(n, vector<int>(11));
    for (auto &v: is_open) {
        for (auto &f: v) cin >> f;
    }
    for (auto &v: profits) {
        for (auto &p: v) cin >> p;
    }
    int ans = - 1e9;
    for (int b = 1; b < 1<<10; b++) {
        int ans_temp = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < 10; j++) {
                if ((b>>j & 1) && is_open[i][j]) cnt++;
            }
            ans_temp += profits[i][cnt];
        }
        ans = max(ans, ans_temp);
    }
    cout << ans << endl;
    return 0;
}