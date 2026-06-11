#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

using ll = long long;
using ull = unsigned long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecull = vector<ull>;

using vec2 = pair<ll, ll>;

int main(void) {
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> s(H, vector<char>(W));

    ll wtcnt = 0;
    rep(i, H) {
        rep(k, W) {
            cin >> s[i][k];
            if (s[i][k] == '.') wtcnt++;
        }
    }

    queue<vec2> que;
    vector<vecll> used(H, vecll(W, 0));
    used[0][0] = 1;
    que.push(make_pair(0, 0));
    const static int dx[] = {0, 1, 0, -1};
    const static int dy[] = {-1, 0, 1, 0};

    while (!que.empty()) {
        vec2 pos = que.front(); que.pop();

        for (int i = 0; i < 4; ++i) {
            int tx = pos.second + dx[i];
            int ty = pos.first + dy[i];

            if (ty < 0 || ty >= H || tx < 0 || tx >= W) continue;
            if (used[ty][tx] != 0) continue;
            if (s[ty][tx] == '#') continue;

            used[ty][tx] = used[pos.first][pos.second] + 1;
            que.push(make_pair(ty, tx));


        }

    }

    ll ans;
    if (used[H - 1][W - 1] == 0) ans = -1;
    else ans = wtcnt - used[H - 1][W - 1];

    cout << ans << endl;


    return 0;
}
