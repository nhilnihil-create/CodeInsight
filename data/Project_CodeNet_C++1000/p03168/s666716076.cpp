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

double dp[3005][3005];

int main(int, const char**)
{
    int n;
    cin >> n;
    dp[0][0] = 1;
    rep(i, n)
    {
        double r;
        cin >> r;

        auto c = i + 1;
        auto nr = 1 - r;
        rep(j, c + 1)
        {
            if(j == 0)
            {
                dp[c][j] = dp[c - 1][j] * nr;
                continue;
            }
            dp[c][j] = (dp[c - 1][j] * nr) + dp[c - 1][j - 1] * r;
        }
    }
    double ans = 0;
    rep(i, (n + 1) / 2)
    {
        ans += dp[n][i];
    }
    printf("%.10f\n", 1 - ans);
    return 0;
}
