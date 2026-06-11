#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W));
    REP(i, H) REP(j, W) cin >> a[i][j];
    vector<vector<int>> ans;
    REP(i, H) {
        REP(j, W) {
            if (a[i][j] % 2 == 1) {
                if (j < W - 1) {
                    a[i][j+1]++;
                    ans.push_back({i+1, j+1, i+1, j+2});
                } else if (i < H - 1) {
                    a[i+1][j]++;
                    ans.push_back({i+1, j+1, i+2, j+1});
                }
            }
        }
    }
    cout << ans.size() << '\n';
    REP(i, ans.size()) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << '\n';
    }
}