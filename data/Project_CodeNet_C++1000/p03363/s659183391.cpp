// 問題の URL を書いておく
// https://atcoder.jp/contests/agc023/tasks/agc023_a

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
    int n;
    cin >> n;
    vector<ll> s(n + 1, 0);
    rep(i, n)
    {
        ll a;
        cin >> a;
        s[i + 1] = s[i] + a;
    }

    sort(s.begin(), s.end());
    ll t = 0;
    ll c = 0;
    ll ans = 0;
    rep(i, n + 1)
    {
        if(s[i] == t)
        {
            c++;
        }
        else
        {
            if(c >= 2)
            {
                ans += (c * (c - 1) / 2);
            }
            c = 1;
            t = s[i];
        }
    }
    if(c >= 2)
    {
        ans += (c * (c - 1) / 2);
    }
    cout << ans << endl;

    return 0;
}
