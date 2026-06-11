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

    int n, k;
    cin >> n >> k;

    int l, r;
    l = r = 0;
    vs32 x;
    rep (i, n)
    {
        int temp;
        cin >> temp;
        if (temp < 0)
        {
            x.push_back(temp);
            ++l;
        }
        else if (temp > 0)
        {
            x.push_back(temp);
            ++r;
        }
        else --k;
    }

    if (k == 0)
    {
        cout << "0\n";
        return 0;
    }

    int ans = 1e9;
    for (int i = l; i >= MAX(1, k - r); --i)
    {
        if (i >= k) ans = MIN(ans, -x[l - k]);
        else ans = MIN(ans, 2 * (-x[l - i]) + x[l + k - i - 1]);
    }

    for (int i = r; i >= MAX(1, k - l); --i)
    {
        if (i >= k) ans = MIN(ans, x[l + k - 1]);
        else ans = MIN(ans, 2 * x[l + i - 1] - x[l - k + i]);
    }

    cout << ans << "\n";
    return 0;
}

