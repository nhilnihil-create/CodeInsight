#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
#define M 1000000007
int h, w;
bool G[1001][1001];
int dp[1001][1001];

int main() {
    cin >> h >> w;
    reps(y, h) reps(x, w) {
        char c;
        cin >> c;
        G[y][x] = (c == '#');
    }
    reps(y, h) reps(x, w) {
        if (x == 1 && y == 1) {
            dp[y][x] = 1;
            continue;
        }
        if (!G[y][x])
            dp[y][x] = (dp[y - 1][x] + dp[y][x - 1]) % M;
    }
    cout << dp[h][w] << endl;
    return 0;
}