#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W)), ans;
    rep(i, H) {
        rep(j, W) {
            cin >> a[i][j];
        }
    }
    rep(i, H) {
        rep(j, W - 1) {
            if (a[i][j] % 2) {
                ans.push_back({i, j, i, j + 1});
                a[i][j]--;
                a[i][j + 1]++;
            }
        }
    }
    rep(i, H - 1) {
        if (a[i][W - 1] % 2) {
            ans.push_back({i, W - 1, i + 1, W - 1});
            a[i][W - 1]--;
            a[i + 1][W - 1]++;
        }
    }
    cout << ans.size() << "\n";
    rep(i, ans.size()) {
        rep(j, 4) {
            cout << ans[i][j] + 1;
            if (j == 3) cout << "\n";
            else cout << " ";
        }
    }
}