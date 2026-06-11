// 問題の URL を書いておく
// 

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

//#define ENABLE_PRINT

#if defined(ENABLE_PRINT)

#define Print(v) \
do {\
    cout << #v << ": " << v << endl; \
}while(0)

#define PrintVec(v) \
do {\
    for(int __i = 0; __i < v.size(); ++__i) \
    { \
        cout << #v << "[" << __i << "]: " << v[__i] << endl; \
    }\
}while(0)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)

#endif

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

using ll = int64_t;

const int HMax = 1005;
const int WMax = 1005;
const int M = 1e9 + 7;
ll dp[HMax][WMax];

int main(int, const char**)
{
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H)
    {
        cin >> grid[i];
    }
    dp[0][0] = 1;
    struct Point
    {
        int x;
        int y;
    };
    queue<Point> q;
    q.push({0, 0});
    rep(i, H)
    {
        rep(j, W)
        {
            if(i == 0 && j == 0 && grid[0][0] == '.')
            {
                dp[0][0] = 1;
                continue;
            }
            if(grid[i][j] == '.')
            {
                auto u = i == 0 ? 0 : dp[i - 1][j];
                auto l = j == 0 ? 0 : dp[i][j - 1];
                dp[i][j] = (u + l) % M;
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl;
    return 0;
}
