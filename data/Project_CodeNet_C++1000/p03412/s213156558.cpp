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

    int n;
    cin >> n;

    vs32 a(n), b(n);
    rep (i, n) cin >> a[i];
    rep (i, n) cin >> b[i];
    // sort(b.begin(), b.end());

    int ans = 0;
    rep (i, 29)
    {
        int mask = (1 << (i + 1)) - 1;
        vs32 B(n);
        rep (j, n) B[j] = b[j] & mask;
        sort(B.begin(), B.end());

        s64 num = 0;
        int t = 1 << i;
        rep (j, n)
        {
            int A = a[j] & mask;
            num += lower_bound(B.begin(), B.end(), 2 * t - A) - lower_bound(B.begin(), B.end(), t - A);
            num += lower_bound(B.begin(), B.end(), 4 * t - A) - lower_bound(B.begin(), B.end(), 3 * t - A);
        }
        if (num & 1) ans |= 1 << i;
    }

    cout << ans << "\n";

    return 0;
}

