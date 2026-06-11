// 問題の URL を書いておく
// https://atcoder.jp/contests/agc031/tasks/agc031_a

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

const int M = 1000000007;
#if 1
int main(int, const char**)
{
    map<char, int> counts;
    int n;
    cin >> n;
    ll ans = 1;
    string s;
    cin >> s;
    for(auto c : s)
    {
        if(counts.find(c) == counts.end())
        {
            counts[c] = 0;
        }
        counts[c]++;
    }

    for(auto c : counts)
    {
        ans *= (c.second + 1);
        ans %= M;
    }
    cout << (ans - 1 + M) % M << endl;

    return 0;
}
#else
int main(int, const char**)
{
    set<char> dup;
    int n;
    cin >> n;
    int prev = 0;
    int ans = 0;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    for(auto c : s)
    {
        if(dup.find(c) == dup.end())
        {
            prev = ans;
            ans = ans * 2 % M + 1;
            ans %= M;
            dup.insert(c);
        }
        else
        {
            ans = (ans + prev + 1) % M;
        }
    }
    cout << ans << endl;

    return 0;
}
#endif