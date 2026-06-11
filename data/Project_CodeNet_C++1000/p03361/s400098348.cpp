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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> hw(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> hw[i][j];
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    rep(i, h) rep(j, w) {
        if (hw[i][j] != '#') continue;
        bool ok = false;
        rep(k, 4) {
            int y = i + dy[k];
            int x = j + dx[k];
            if (y < 0 || y >= h || x < 0 || x >= w) continue;
            if (hw[y][x] == '#') ok = true;
        }
        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
