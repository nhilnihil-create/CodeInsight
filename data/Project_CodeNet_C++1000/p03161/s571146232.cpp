// 問題の URL を書いておく
// https://atcoder.jp/contests/dp/tasks/dp_a

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

int main(int, const char**)
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }
    vector<ll> dp(n + k + 5, numeric_limits<ll>::max());
    dp[0] = 0;
    rep(i, n)
    {
        rep(j, k)
        {
            dp[i + 1 + j] = min(dp[i + 1 + j], dp[i] + abs(h[i] - h[i + 1 + j]));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
