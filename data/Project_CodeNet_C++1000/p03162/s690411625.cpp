// 問題の URL を書いておく
// https://atcoder.jp/contests/dp/tasks/dp_c

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

ll dp[100005][3] = {};

int main(int, const char**)
{
    int n;
    cin >> n;
    rep(i, n)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        dp[i + 1][0] = max(dp[i][1] + a, dp[i][2] + a);
        dp[i + 1][1] = max(dp[i][0] + b, dp[i][2] + b);
        dp[i + 1][2] = max(dp[i][0] + c, dp[i][1] + c);
    }
    cout << max(dp[n][2], max(dp[n][0], dp[n][1])) << endl;
    return 0;
}
