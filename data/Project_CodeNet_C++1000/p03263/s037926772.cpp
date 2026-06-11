#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> grids(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grids[i][j];
        }
    }

    int c = 0;
    vector<vector<int>> ans;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W-1; j++) {
            if (grids[i][j] % 2 == 1) {
                c++;
                ans.push_back({i+1, j+1, i+1, j+2});
                grids[i][j+1]++;
            }
        }
    }
    for (int i = 0; i < H-1; i++) {
        if (grids[i][W-1] % 2 == 1) {
            c++;
            ans.push_back({i+1, W, i+2, W});
            grids[i+1][W-1]++;
        }
    }
    cout << c << endl;
    for (int i = 0; i < c; i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << endl;
    }
}