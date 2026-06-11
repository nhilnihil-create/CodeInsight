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

using P = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector< P > red(n), blue(n);
    rep (i, n) cin >> red[i].first >> red[i].second;
    rep (i, n) cin >> blue[i].first >> blue[i].second;

    sort(red.begin(), red.end(), greater<P>());
    sort(blue.begin(), blue.end());

    vector< bool > used(n, false);
    int ans = 0;
    rep (i, n)
    {
        int idx = -1;
        int ym = 300;
        rep (j, n)
        {
            if (!(used[j] || red[i].first >= blue[j].first || red[i].second >= blue[j].second))
            {
                if (ym > blue[j].second)
                {
                    ym = blue[j].second;
                    idx = j;
                }
            }
        }
        if (idx == -1) continue;
        ++ans;
        used[idx] = true;
    }

    cout << ans << "\n";
    return 0;
}

