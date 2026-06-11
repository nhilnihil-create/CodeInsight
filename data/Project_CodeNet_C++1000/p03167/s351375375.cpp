#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const long long MOD = 1e9 + 7;
const int MAXH = 1000 + 5;

struct Pos {
    int x;
    int y;
};

int h, w;
long long dp[MAXH][MAXH];
char board[MAXH][MAXH];

void calc(int x, int y) {
    if (x < 1 || y > w) {
        return;
    }
    if (x - 1 >= 1 && board[x - 1][y] != '#') {
        dp[x][y] = (dp[x][y] + dp[x - 1][y]) % MOD;
    }
    if (y - 1 >= 1 && board[x][y - 1] != '#') {
        dp[x][y] = (dp[x][y] + dp[x][y - 1]) % MOD;
    }
    calc(x - 1, y + 1);
}

void solve(int x, int y) {
    if (y > w) {
        return;
    }
    if (x == h) {
        calc(x, y);
        solve(x, y + 1);
    } else {
        calc(x, y);
        solve(x + 1, y);
    }
}

int main() {
    IOS

    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> board[i][j];
        }
    }

    dp[1][1] = 1;
    solve(1, 1);

    cout << dp[h][w] << '\n';
}