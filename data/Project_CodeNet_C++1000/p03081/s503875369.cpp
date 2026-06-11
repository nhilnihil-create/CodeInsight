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

int n, q;
string s;
string t;
string d;

bool ok(int x, int mode)
{
    rep (i, q)
    {
        if (d[i] == 'L')
        {
            if (s[x] == t[i]) --x;
            if (x < 0) return mode == 1;
        }
        else
        {
            if (s[x] == t[i]) ++x;
            if (x >= n) return mode == 0;
        }
    }

    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> q;

    cin >> s;

    t.resize(q);
    d.resize(q);
    rep (i, q)
    {
        cin >> t[i] >> d[i];
    }

    int ans = n;
    int l, r;
    l = -1; r = n;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (ok(m, 0)) r = m;
        else l = m;
    }
    ans -= r;

    l = -1; r = n;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (ok(m, 1)) l = m;
        else r = m;
    }
    ans -= n - l - 1;

    cout << ans << "\n";
    return 0;
}

