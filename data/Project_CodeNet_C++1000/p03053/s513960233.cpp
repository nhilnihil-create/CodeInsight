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
    queue<pair<int, int>> que;
    int cnt = 0;
    rep(i, h) rep(j, w) {
        cin >> hw[i][j];
        if (hw[i][j] == '#') {
            que.push(make_pair(i, j));
            ++cnt;
        }
    }
    int ans = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(!que.empty()) {
        pair<int, int> now = que.front(); que.pop();
        --cnt;
        rep(ri, 4) {
            int y = now.first + dy[ri];
            int x = now.second + dx[ri];
            if (y < 0 || y >= h || x < 0 || x >= w) continue;
            if (hw[y][x] == '#') continue;
            hw[y][x] = '#';
            que.push(make_pair(y, x));
        }
        //cout << cnt << " " << que.size() << endl;
        if (cnt == 0 && !que.empty()) {
            ++ans;
            cnt = que.size();
        }
    }
    cout << ans << endl;
    return 0;
}
