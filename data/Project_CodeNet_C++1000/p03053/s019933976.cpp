#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換

int main() {
    int h, w;
    cin >> h >> w;
    int a[] = {1, 0, -1, 0};
    int b[] = {0, 1, 0, -1};
    char A[h][w];
    int point[h][w];
   queue<pair<int,int>> que;
    rep(i, h) {
        rep(j, w) {
            cin >> A[i][j];
            point[i][j] = 0;
            if (A[i][j] == '#') {
                que.push(make_pair(i, j));
            }
        }
    }

    while (!que.empty()) {
        int ny = que.front().first, nx = que.front().second;
        que.pop();

        rep(i, 4) {
            int y = ny + a[i], x = nx + b[i];
            if (y < 0 || y >= h || x < 0 || x >= w || A[y][x] == '#')
                continue;
            point[y][x] = point[ny][nx] + 1;
            A[y][x] = '#';
            que.push(make_pair(y,x));
        }
    }
    int ans = 0;
    rep(i, h) {
        rep(j, w) {
            ans = max(ans, point[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}