// https://atcoder.jp/contests/abc088/tasks/abc088_d
// (白いマスの個数) - (最短経路でゴールする際に通る白いマスの個数)
// 幅優先探索で最短経路を通る時の白いマスの個数を算出する
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using P = pair<int, int>;
P u = P(-1, 0);
P d = P(1, 0);
P l = P(0, -1);
P r = P(0, 1);
P dir[4] = { u, d, l, r };

int main()
{
    int H, W;
    scanf("%d %d", &H, &W);
    vector<vector<bool>> s(H, vector<bool>(W));
    int white = 0;
    for (int i = 0; i < H; ++i)
    {
        char str[60];
        scanf("%s", str);
        for (int j = 0; j < W; ++j)
        {;
            if (str[j] == '.')
            {
                s[i][j] = true;
                ++white;
            }
            else
            {
                s[i][j] = false;
            }
        }
    }
    constexpr int inf = 1 << 30;
    vector<vector<int>> dp(H, vector<int>(W, inf));
    dp[0][0] = 1;
    queue<P> q;
    q.push(P(0, 0));
    while(!q.empty())
    {
        P cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            P next = P(cur.first + dir[i].first, cur.second + dir[i].second);
            if (next.first >= 0 && next.first < H && next.second >= 0 && next.second < W && s[next.first][next.second])
            {
                dp[next.first][next.second] = dp[cur.first][cur.second] + 1;
                s[next.first][next.second] = false;
                q.push(next);
            }
        }
    }
    
    if (s[H - 1][W - 1])
    {
        printf("%d\n", -1);
        return 0;
    }

    printf("%d\n", white - dp[H - 1][W - 1]);
    
    return 0;
}
