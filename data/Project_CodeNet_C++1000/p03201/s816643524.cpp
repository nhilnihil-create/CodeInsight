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

    map< s64, int > m;
    vs64 a(n);
    rep (i, n)
    {
        cin >> a[i];
        ++m[a[i]];
    }

    sort(a.begin(), a.end(), greater<s64>());

    s64 ans = 0;
    rep (i, n)
    {
        s64 target = 1;
        while (target <= a[i]) target <<= 1;
        if (m[target - a[i]] == 0)
        {
            continue;
        }

        if (a[i] * 2 == target)
        {
            if (m[a[i]] > 1)
            {
                m[a[i]] -= 2;
                ++ans;
            }
        }
        else if (m[a[i]] > 0 && m[target - a[i]] > 0)
        {
            --m[a[i]];
            --m[target - a[i]];
            ++ans;
        }
    }

    cout << ans << "\n";
    return 0;
}

