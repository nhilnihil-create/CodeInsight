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


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vs64 x(n);
    vs64 a(n), b(n);
    rep (i, n) cin >> a[i];
    rep (i, n) cin >> b[i];
    rep (i, n) x[i] = a[i] - b[i];
    sort(x.begin(), x.end());

    int l = 0;
    int r = n - 1;
    enum {
        BLACK = 2,
        GRAY  = 1,
        WHITE = 0
    };
    vs32 color(n, WHITE);
    while (x[l] < 0 && x[r] > 0)
    {
        s64 temp = x[r] + x[l];
        if (temp >= 0)
        {
            x[r] = temp;
            x[l] = 0;
            color[r] = GRAY;
            color[l] = BLACK;
            ++l;
        }
        else
        {
            x[r] = 0;
            x[l] = temp;
            color[r] = BLACK;
            color[l] = GRAY;
            --r;
        }
    }

    int ans = 0;
    if (x[l] >= 0)
    {
        rep (i, n)
        {
            if (color[i] != WHITE) ++ans;
        }
    }
    else
    {
        ans = -1;
    }
    cout << ans << "\n";
    return 0;
}

