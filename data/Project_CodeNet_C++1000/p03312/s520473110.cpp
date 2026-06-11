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
    vs64 s(n + 1, 0);
    s64 a;
    rep (i, n)
    {
        cin >> a;
        s[i + 1] = s[i] + a;
    }

    s64 ans = 1e18;
    for (int m = 2; m <= n - 2; ++m)
    {
        s64 pq = s[m];
        s64 rs = s[n] - s[m];
        auto lm = upper_bound(s.begin(), s.begin() + m + 1, pq / 2);
        auto rm = upper_bound(s.begin() + m + 1, s.end(), rs / 2 + s[m]);
        s64 pqrs[8] = {*(lm - 1), pq - *(lm - 1), *lm, pq - *lm,
                        *(rm - 1) - s[m], s[n] - *(rm - 1), *rm - s[m], s[n] - *rm};
        rep (i, 2)
        {
            rep (j, 2)
            {
                s64 large = 0, small = 1e18;
                large = MAX(large, pqrs[i * 2]);
                large = MAX(large, pqrs[i * 2 + 1]);
                large = MAX(large, pqrs[4 + j * 2]);
                large = MAX(large, pqrs[4 + j * 2 + 1]);
                small = MIN(small, pqrs[i * 2]);
                small = MIN(small, pqrs[i * 2 + 1]);
                small = MIN(small, pqrs[4 + j * 2]);
                small = MIN(small, pqrs[4 + j * 2 + 1]);
                ans = MIN(ans, large - small);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

