#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> coin(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> coin[i][j];

    vector<pair<int, int>> start, end;
    rep(i, h) {
        if (i % 2 == 0) {
            rep(j, w) {
                if (coin[i][j] % 2) {
                    if (j == w - 1) {
                        if (i != h - 1) {
                            start.push_back({i, j});
                            end.push_back({i + 1, j});
                            --coin[i][j];
                            ++coin[i + 1][j];
                        }
                    } else {
                        start.push_back({i, j});
                        end.push_back({i, j + 1});
                        --coin[i][j];
                        ++coin[i][j + 1];
                    }
                }
            }
        } else {
            for (int j = w - 1; j >= 0; --j) {
                if (coin[i][j] % 2) {
                    if (j == 0) {
                        if (i != h - 1) {
                            start.push_back({i, j});
                            end.push_back({i + 1, j});
                            --coin[i][j];
                            ++coin[i + 1][j];
                        }
                    } else {
                        start.push_back({i, j});
                        end.push_back({i, j - 1});
                        --coin[i][j];
                        ++coin[i][j - 1];
                    }
                }
            }
        }
    }

    cout << start.size() << endl;
    rep(i, start.size()) {
        cout << start[i].first + 1 << " " << start[i].second + 1 << " "
             << end[i].first + 1 << " " << end[i].second + 1 << "\n";
    }

    return 0;
}