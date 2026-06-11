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

struct Vertex
{
    vector<int> next;
    vector<int> prev;
};

int dp[100005];
bool done[100005];

int calc(int end, vector<Vertex>& vs)
{
    if(done[end])
    {
        return dp[end];
    }

    int maxDist = 0;
    auto& v = vs[end];

    if(v.prev.size() == 0)
    {
        done[end] = true;
        dp[end] = 0;
        return 0;
    }

    for(auto p : v.prev)
    {
        maxDist = max(maxDist, calc(p, vs));
    }
    done[end] = true;
    dp[end] = maxDist + 1;
    return dp[end];
}

int main(int, const char**)
{
    int N, M;
    cin >> N >> M;
    vector<Vertex> vs(N + 1);
    rep(i, M)
    {
        int x, y;
        cin >> x >> y;
        vs[x].next.push_back(y);
        vs[y].prev.push_back(x);
    }

    int ans = 0;
    rep(i, N)
    {
        auto vi = i + 1;
        ans = max(ans, calc(vi, vs));
    }
    cout << ans << endl;

    return 0;
}
