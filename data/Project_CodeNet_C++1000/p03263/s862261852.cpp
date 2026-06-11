#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct T {
    int y1, x1, y2, x2;
};

int main() {
    int h, w;
    cin >> h >> w;
    int grid[h][w];
    rep (i, 0, h) rep (j, 0, w) cin >> grid[i][j];
    vector<T> vec;
    rep (i, 0, h) {
        rep (j, 0, w) {
            if (grid[i][j] % 2 == 1) {
                if (j != w - 1) {
                    grid[i][j]--;
                    grid[i][j + 1]++;
                    vec.push_back ({i + 1, j + 1, i + 1, j + 2});
                } else {
                    if (i == h - 1) continue;
                    else {
                        grid[i][j]--;
                        grid[i + 1][j]++;
                        vec.push_back ({i + 1, j + 1, i + 2, j + 1});
                    }
                }
            }
        }
    }
    cout << vec.size() << "\n";
    for (auto p : vec) {
        cout << p.y1 << " " << p.x1 << " " << p.y2 << " " << p.x2 << "\n";
    }
}