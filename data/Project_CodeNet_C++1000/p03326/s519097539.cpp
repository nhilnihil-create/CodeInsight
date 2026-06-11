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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector< vs64 > c(8, vs64(n, 0));

    vs64 data(3);
    rep (i, n)
    {
        cin >> data[0] >> data[1] >> data[2];
        rep (j, 8)
        {
            int temp = j;
            rep (k, 3)
            {
                c[j][i] += (temp & 1 ? data[k] : -data[k]);
                temp >>= 1;
            }
        }
    }

    rep (j, 8)
    {
        sort(c[j].begin(), c[j].end(), greater<s64>());
    }

    s64 ans = 0;
    rep (j, 8)
    {
        s64 sum = accumulate(c[j].begin(), c[j].begin() + m, (s64)0);
        ans = MAX(ans, sum);
    }

    cout << ans << "\n";
    return 0;
}

