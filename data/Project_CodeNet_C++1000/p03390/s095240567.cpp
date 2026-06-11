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

    int q;
    cin >> q;

    while (q--)
    {
        s64 a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);
        s64 l = 0;
        s64 r = (s64)1e9;
        while (l + 1 < r)
        {
            s64 m = (l + r) / 2;
            if (m * m - a * b < 0) l = m;
            else r = m;
        }
        s64 ans = 2 * l;
        if (IN(1, r, a))
        {
            --ans;
            if (a * b % l == 0) ans -= l == a * b / l - 1;
            else ans -= l == a * b / l;
        }
        cout << ans << "\n";
    }

    return 0;
}

