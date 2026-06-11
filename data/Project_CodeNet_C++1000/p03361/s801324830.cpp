#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> hw(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> hw[i][j];
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    rep(i, h) rep(j, w) {
        if (hw[i][j] == '#') {
            bool flg = false;
            rep(k, 4) {
                int check_y = i + dy[k];
                int check_x = j + dx[k];
                if (check_y < 0 || check_y >= h || check_x < 0 || check_x >= w) continue;
                if (hw[check_y][check_x] == '#') {
                    flg = true;
                }
            }
            if (!flg) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
