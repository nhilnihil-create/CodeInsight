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

int convPoints[51][51];
int sums[51][51];

int main()
{
    int N, K; cin >> N >> K;
    vector<pair<int, int>> points(N);
    set<int> xs, ys;
    for (int i = 0; i < N; ++i)
    {
        int x, y; cin >> x >> y;
        points[i] = { x, y };
        xs.insert(x);
        ys.insert(y);
    }
    // 座標を昇順に並べ替え2次元和にする
    map<int, int> x2IndexMap, y2IndexMap;
    map<int, LLONG> index2XMap, index2YMap;
    x2IndexMap.insert({ -2e9, 0 });
    y2IndexMap.insert({ -2e9, 0 });
    int index = 1;
    for (const int x : xs)
    {
        x2IndexMap.insert({ x, index });
        index2XMap.insert({ index, x });
        ++index;
    }
    index = 1;
    for (const int y : ys)
    {
        y2IndexMap.insert({ y, index });
        index2YMap.insert({ index, y });
        ++index;
    }
    for (int i = 0; i < N; ++i)
    {
        int xInd = x2IndexMap[points[i].first];
        int yInd = y2IndexMap[points[i].second];
        convPoints[xInd][yInd] = 1;
    }
    for (int i = 1; i < 51; ++i)
    {
        for (int j = 1; j < 51; ++j)
        {
            sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + convPoints[i][j];
        }
    }
    // 2次元和を全探索:O(N^4)
    LLONG ans = 9223372036854775807;
    for (int x1 = 1; x1 <= N; ++x1) for (int x2 = x1; x2 <= N; ++x2)
        for (int y1 = 1; y1 <= N; ++y1) for (int y2 = y1; y2 <= N; ++y2)
        {
        int sum = sums[x2][y2] - sums[x1 - 1][y2] - sums[x2][y1 - 1] + sums[x1 - 1][y1 - 1];
        if (sum >= K)
        {
            LLONG area = (index2XMap[x2] - index2XMap[x1]) * (index2YMap[y2] - index2YMap[y1]);
            if (ans > area)
            {
                ans = area;
            }
        }
        }
    cout << ans << endl;
}