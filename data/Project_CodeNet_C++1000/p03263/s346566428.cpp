#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int H, W; cin >> H >> W;
    vector<vector<int>> as(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> as[i][j];
        }
    }
    // 一筆書きの経路を作り，経路上の奇数を次の奇数まで順次移動させていく
    struct Pos
    {
        int R; int C;
    };
    vector<Pos> line;
    for (int r = 1; r <= H; ++r)
    {
        if (r % 2 == 1)
        {
            for (int c = 1; c <= W; ++c) line.push_back({ r, c });
        }
        else
        {
            for (int c = W; c >= 1; --c) line.push_back({ r, c });
        }
    }
    vector<pair<Pos, Pos>> ans;
    vector<pair<Pos, Pos>> tmp;
    bool movingOdd = false;
    for (int i = 0; i < H * W - 1; ++i)
    {
        const auto pos = line[i];
        // 奇数を見つけたとき
        if (as[pos.R - 1][pos.C - 1] % 2 == 1)
        {
            // 既に奇数を移動中ならば，ここで移動を終了
            // これまで記録してきた移動経路を答えに追加
            if (movingOdd)
            {
                movingOdd = false;
                ans.insert(ans.end(), tmp.begin(), tmp.end());
                tmp.clear();
            }
            // 奇数を移動中でないならば，この奇数を移動開始する
            // 次の点への移動経路を記録
            else
            {
                movingOdd = true;
                tmp.push_back({ pos, line[i + 1] });
            }
        }
        // 奇数でないとき
        // 奇数を移動中ならば，次の点への移動経路を記録
        else
        {
            if (movingOdd)
            {
                tmp.push_back({ pos, line[i + 1] });
            }
        }
    }
    // 最後の点が奇数のとき
    // 奇数を移動させていたならば，これまでの移動記録を答えに追加
    if (as[line.back().R - 1][line.back().C - 1] % 2 == 1)
    {
        if (movingOdd)
        {
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
    }
    cout << ans.size() << endl;
    for (const auto &move : ans)
    {
        cout << move.first.R << ' ' << move.first.C << ' '
            << move.second.R << ' ' << move.second.C << endl;
    }
}
