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

int n, m;
vs64 x, y, z;

s64 solve(int i)
{
    static const s64 sign[2] = {1, -1};

    s64 ret = 0;
    int a, b, c;
    a = (i >> 2) & 1;
    b = (i >> 1) & 1;
    c = (i >> 0) & 1;
    vs64 cand(n);
    rep (i, n)
    {
        cand[i] = sign[a] * x[i] + sign[b] * y[i] + sign[c] * z[i];
    }
    sort(cand.begin(), cand.end(), greater<s64>());

    rep (i, m)
    {
        ret += cand[i];
    }

    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    x.resize(n);
    y.resize(n);
    z.resize(n);
    rep (i, n)
    {
        cin >> x[i] >> y[i] >> z[i];
    }

    s64 ans = 0;
    rep (i, 8)
    {
        ans = MAX(ans, solve(i));
    }

    cout << ans << "\n";
    return 0;
}

