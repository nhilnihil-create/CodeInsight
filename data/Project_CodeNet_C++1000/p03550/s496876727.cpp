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
    int z, w;
    cin >> n >> z >> w;

    vs32 a(n);
    rep (i, n) cin >> a[i];

    vs32 M(n, 0);
    vs32 m(n, 1e9);
    M[n - 1] = m[n - 1] = abs(a[n - 1] - w);
    for (int i = n - 2; i >= 0; --i)
    {
        if (i < n - 2)
        {
            M[i] = M[i + 1];
            m[i] = m[i + 1];
        }
        for (int j = i + 1; j < n; ++j)
        {
            M[i] = MAX(M[i], abs(a[i] - a[j]));
            m[i] = MIN(m[i], abs(a[i] - a[j]));
        }
    }

    int x = 0, y = 0;
    int flag = 1;
    while (x != n - 1 && y != n - 1)
    {
        if (flag == 1)
        {
            int temp = -1;
            for (int i = y; i < n; ++i)
            {
                if (temp <= m[i])
                {
                    temp = m[i];
                    x = i;
                }
            }
        }
        else
        {
            int temp = 1e9 + 1;
            for (int i = x; i < n; ++i)
            {
                if (temp >= M[i])
                {
                    temp = M[i];
                    y = i;
                }
            }
        }
        flag ^= 1;
    }

    int ans = (y == 0 ? abs(w - a[n - 1]) : abs(a[x] - a[y]));
    cout << ans << "\n";
    return 0;
}

