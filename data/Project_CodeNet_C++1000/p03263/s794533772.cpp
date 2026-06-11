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
    REP(i, H) {
        REP(j, W) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> ans;
    REP(i, H-1) {
        REP(j, W) {
            if (a[i][j] % 2 == 1) {
                a[i][j]--;
                a[i+1][j]++;
                ans.push_back({i+1, j+1, i+2, j+1});
            }
        }
    }
    REP(j, W-1) {
        if (a[H-1][j] % 2 == 1) {
            a[H-1][j]--;
            a[H-1][j+1]++;
            ans.push_back({H, j+1, H, j+2});
        }
    }
    cout << ans.size() << endl;
    for (auto& v : ans) cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
}