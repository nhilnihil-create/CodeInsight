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
#include <numeric>

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

class Rect
{
public:
    s64 l, r, u, d;
    Rect(int l, int r, int u, int d)
    : l(l), r(r), u(u), d(d)
    {}

    bool in(int x, int y)
    {
        return IN(l, r + 1, x) && IN(u, d + 1, y);
    }

    s64 area()
    {
        return (r - l) * (d - u);
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vs32 x(n), y(n);
    rep (i, n)
    {
        cin >> x[i] >> y[i];
    }

    s64 ans = ((s64)1 << 62);
    rep (p, n) rep (q, n) rep (r, n) rep(s, n)
    {
        if (p == q || r == s) continue;
        int ll = MIN(x[p], x[q]);
        int rr = MAX(x[p], x[q]);
        int uu = MIN(y[r], y[s]);
        int dd = MAX(y[r], y[s]);
        Rect rec(ll, rr, uu, dd);
        int cnt = 0;
        rep (i, n)
        {
            if (rec.in(x[i], y[i]))
            {
                ++cnt;
            }
        }
        if (cnt >= k)
        {
            ans = MIN(ans, rec.area());
        }
    }

    cout << ans << "\n";

    return 0;
}

