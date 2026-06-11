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

int solve(vs32& t)
{
    int ret = 12;
    int n = t.size();
    rep (i, n)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int dM = MAX(t[i], t[j]);
            int dm = MIN(t[i], t[j]);
            int gap = MIN(24 - dM + dm, dM - dm);
            ret = MIN(ret, gap);
        }
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vs32 d(n + 1);
    d[0] = 0;
    vs32 cnt(13,  0);
    cnt[0] = 1;
    rep (i, n)
    {
        cin >> d[i + 1];
        ++cnt[d[i + 1]];
    }

    rep (i, 13)
    {
        if ((i == 0 && cnt[i] > 1) || (i == 12 && cnt[i] > 1) || cnt[i] > 2)
        {
            cout << "0\n";
            return 0;
        }
    }

    int ans = 0;
    rep (i, 1 << 11)
    {
        vs32 time;
        int temp = i << 1;
        rep (j, 13)
        {
            if ((j == 0 && cnt[j] > 0) || (j == 12 && cnt[j] > 0))
            {
                time.push_back(j);
            }
            else if (cnt[j] == 0)
            {
                continue;
            }
            else if (cnt[j] == 2)
            {
                time.push_back(j);
                time.push_back(24 - j);
            }
            else if (temp & 1)
            {
                time.push_back(24 - j);
            }
            else
            {
                time.push_back(j);
            }
            temp >>= 1;
        }
        ans = MAX(ans, solve(time));
    }

    cout << ans << "\n";
    return 0;
}

