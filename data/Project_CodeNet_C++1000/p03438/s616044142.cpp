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

int main(int, const char**)
{
    int n;
    cin >> n;
    vector<int> a(n);
    int64_t totalA = 0;
    rep(i, n)
    {
        cin >> a[i];
        totalA += a[i];
    }
    int64_t totalB = 0;
    int64_t bFitCount = 0;
    int64_t aFitCount = 0;
    rep(i, n)
    {
        int64_t b;
        cin >> b;
        totalB += b;
        if(a[i] - b > 0)
        {
            bFitCount += a[i] - b;
        }
        else
        {
            aFitCount += (b - a[i] + 1) / 2;
        }
    }
    auto tryNum = totalB - totalA;
    if(tryNum >= 0 && bFitCount <= tryNum && aFitCount <= tryNum)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
