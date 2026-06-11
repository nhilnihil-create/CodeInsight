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


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; s64 k;
    cin >> n >> k;
    vs64 a(n);
    rep (i, n)
    {
        cin >> a[i];
    }

    const int max_keta = 40;
    int zeros[max_keta + 1];
    int ones[max_keta + 1];
    rep (i, max_keta + 1) zeros[i] = ones[i] = 0;
    rep (i, max_keta + 1)
    {
        rep (j, n)
        {
            if ((a[j] >> i) & 1) ++ones[i];
            else ++zeros[i];
        }
    }

    s64 ans = 0;
    int keta = max_keta;
    while (keta > 0 && (k >> keta) == 0) --keta;
    for (s64 i = keta; i >= -1; --i)
    {
        s64 w = 0;
        s64 x = 0;
        for (s64 j = keta; j > i; --j)
        {
            if ((k >> j) & 1) x |= 1ll << j;
        }
        for (s64 j = i - 1; j >= 0; --j)
        {
            if (ones[j] < zeros[j]) x |= 1ll << j;
        }
        if (x > k) continue;
        rep (j, n) w += a[j] ^ x;
        ans = max(ans, w);
    }

    cout << ans << "\n";
    return 0;
}

