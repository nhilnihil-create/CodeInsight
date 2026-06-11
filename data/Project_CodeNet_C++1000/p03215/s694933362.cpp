#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

#define IN(l, r, x) ((l) <= (x) && (x) < (r))


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    s64 n, k;
    cin >> n >> k;
    vs64 s(n + 1);
    s[0] = 0;
    s64 a;
    rep (i, n)
    {
        cin >> a;
        s[i + 1] = s[i] + a;
    }

    vs64 A;
    s64 maxA = 0;
    rep (l, n)
    {
        for (int r = l + 1; r <= n; ++r)
        {
            A.push_back(s[r] - s[l]);
            maxA = MAX(maxA, s[r] - s[l]);
        }
    }

    s64 t = 0;
    while (((s64)1 << t) <= maxA) ++t;
    s64 x = 0;
    while (t >= 0)
    {
        s64 y = (s64)1 << t;
        int cnt = 0;
        rep (i, A.size())
        {
            if ((A[i] & (x + y)) == (x + y)) ++cnt;
        }
        if (cnt >= k) x = x + y;
        --t;
    }

    cout << x << "\n";
    return 0;
}

