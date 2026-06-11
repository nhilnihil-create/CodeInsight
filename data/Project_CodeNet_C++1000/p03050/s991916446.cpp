// 問題の URL を書いておく
// https://atcoder.jp/contests/diverta2019/tasks/diverta2019_d

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
using ull = uint64_t;

bool isValid(ull n, ull v)
{
    if(v - 1 == 0)
    {
        return false;
    }
    auto m = v - 1;
    return n / m == n % m;
}

int main(int, const char**)
{
    ull n;
    cin >> n;
    ull ans = 0;
    for(ull i = 1; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            if(isValid(n, i))
            {
                ans += (i - 1);
            }
            if(isValid(n, n / i))
            {
                ans += (n / i - 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
