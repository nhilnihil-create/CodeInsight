#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
using namespace std;
typedef long long ll;

int dx[] = {1, 0};
int dy[] = {0, 1};

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    REP(i, 0, H) REP(j, 0, W) cin >> A[i][j];

    vector<pair<pair<int, int>, pair<int, int>>> ans;
    REP(i, 0, H) {
        REP(j, 0, W) {
            if (A[i][j] % 2 == 0) continue;

            bool moved = false;
            int mi = -1, mj = -1;
            REP(k, 0, 2) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= H || nj >= W) continue;
                if (A[ni][nj] % 2 == 1) {
                    moved = true;
                    A[ni][nj]++;
                    A[i][j]--;
                    ans.push_back({{i + 1, j + 1}, {ni + 1, nj + 1}});
                    break;
                }
                mi = ni; mj = nj;
            }
            if (!moved && mi != -1 && mj != -1) {
                A[mi][mj]++;
                A[i][j]--;
                ans.push_back({{i + 1, j + 1}, {mi + 1, mj + 1}});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto a : ans) cout << a.first.first << " " << a.first.second << " " << a.second.first << " " << a.second.second << endl;

    // cout << "---" << endl;
    // REP(i, 0, H) {
    //     REP(j, 0, W) {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}