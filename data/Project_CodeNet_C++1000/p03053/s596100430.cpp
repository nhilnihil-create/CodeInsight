#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)
#define MAX 50000000

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> s(H+2, vector<char>(W+2));
    vector<vector<int>> check(H+2, vector<int>(W+2, MAX));
    queue<pair<int, int>> q;
    rep(i, W+2) {
        s[0][i] = '#';
        s[H][i] = '#';
    }
    rep(i, H+2) {
        s[i][0] = '#';
        s[i][W+1] = '#';
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> s[i][j];
            if (s[i][j] == '#') {
                check[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    int ans = 0;
    while(!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            if (check[tmp.first+dy[k]][tmp.second+dx[k]] > check[tmp.first][tmp.second] + 1 && s[tmp.first+dy[k]][tmp.second+dx[k]] == '.') {
                q.push(make_pair(tmp.first+dy[k], tmp.second+dx[k]));
                check[tmp.first+dy[k]][tmp.second+dx[k]] = check[tmp.first][tmp.second] + 1;
                ans = max(ans, check[tmp.first+dy[k]][tmp.second+dx[k]]);
            }
        }
    }
    cout << ans << endl;
}
