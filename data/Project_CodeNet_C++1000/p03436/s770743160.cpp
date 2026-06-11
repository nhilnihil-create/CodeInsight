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
    int black_num = 0;
    rep(i, h) rep(j, w) {
        cin >> hw[i][j];
        if (hw[i][j] == '#') ++black_num;
    }
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> cnt(h, vector<int>(w, -1));
    cnt[0][0] = 0;
    while(!que.empty()) {
        pair<int, int> now = que.front(); que.pop();
        if (now.first == h-1 && now.second == w-1) {
            break;
        }
        rep(ri, 4) {
            int y = now.first + dy[ri];
            int x = now.second + dx[ri];
            if (x < 0 || x >= w || y < 0 || y >= h) continue;
            if (hw[y][x] == '#') continue;
            if (cnt[y][x] != -1) continue;
            que.push(make_pair(y, x));
            cnt[y][x] = cnt[now.first][now.second] + 1;
        }
    }
    if (cnt[h-1][w-1] == -1) {
        cout << -1 << endl;
    }
    else {
        cout << h * w - black_num - cnt[h-1][w-1] - 1 << endl; 
    }
    return 0;
}
