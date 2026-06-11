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

int main(int, const char**)
{
    struct Data
    {
        ll n;
        bool f3;
        bool f5;
        bool f7;
    };
    set<ll> nums;
    queue<Data> q;
    q.push({3, true, false, false});
    q.push({5, false, true, false});
    q.push({7, false, false, true});
    while(!q.empty())
    {
        auto d = q.front();
        q.pop();

        if(d.n * 10 < 1000000000)
        {
            q.push({d.n * 10 + 3, true, d.f5, d.f7});
            q.push({d.n * 10 + 5, d.f3, true, d.f7});
            q.push({d.n * 10 + 7, d.f3, d.f5, true});
        }

        if(d.f3 && d.f5 && d.f7)
        {
            nums.insert(d.n);
        }
    }
    int n;
    cin >> n;
    auto f = upper_bound(nums.begin(), nums.end(), n);
    cout << distance(nums.begin(), f) << endl;
    return 0;
}
