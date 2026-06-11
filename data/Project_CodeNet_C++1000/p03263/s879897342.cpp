#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) {
        rep(j, W) {
            cin >> A[i][j];
        }
    }

    vector<int> B;
    vector<pair<int, int>> X;
    for (int i = 0; i < H; i++) {
        // 右から左に移動する
        if (i % 2 == 0) {
            for (int j = 0; j < W; j++) {
                B.push_back(A[i][j]);
                X.push_back(make_pair(i, j));
            }
        }
        // 左から右に移動する
        else {
            for (int j = W - 1; j >= 0; j--) {
                B.push_back(A[i][j]);
                X.push_back(make_pair(i, j));
            }
        }
    }

    int cnt = 0;
    vector<string> ans;
    rep(i, H * W - 1) {
        if (B[i] % 2 != 0) {
            B[i]--;
            B[i + 1]++;
            cnt++;

            ans.push_back(
                to_string(X[i].first + 1) + " " + to_string(X[i].second + 1) + " " + to_string(X[i + 1].first + 1) + " " + to_string(X[i + 1].second + 1)
            );
        }
    }

    cout << cnt << endl;
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }
}