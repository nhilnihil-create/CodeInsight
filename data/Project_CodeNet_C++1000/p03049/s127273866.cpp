// 問題の URL を書いておく
// https://atcoder.jp/contests/diverta2019/tasks/diverta2019_c

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
    int ab = 0, a = 0, b = 0;
    int ans = 0;
    rep(i, n)
    {
        string s;
        cin >> s;
        if(s[0] == 'B' && s.back() == 'A')
        {
            ab++;
        }
        else if(s[0] == 'B')
        {
            b++;
        }
        else if(s.back() == 'A')
        {
            a++;
        }

        rep(j, s.size() - 1)
        {
            if(s[j] == 'A' && s[j + 1] == 'B')
            {
                ans++;
            }
        }
    }
    ans += max(ab - 1, 0);
    if(ab > 0)
    {
        if(a > 0)
        {
            a--;
            ans++;
        }
        if(b > 0)
        {
            b--;
            ans++;
        }
    }
    ans += min(a, b);

    cout << ans << endl;
    return 0;
}
