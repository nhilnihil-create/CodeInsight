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

    vector< string > vs(n);
    rep (i, n) cin >> vs[i];

    int ans = 0;
    int a, b, c;
    a = b = c = 0;

    rep (i, n)
    {
        if (vs[i][0] == 'B' && vs[i][vs[i].size() - 1] == 'A') ++c;
        else if (vs[i][0] == 'B') ++b;
        else if (vs[i][vs[i].size() - 1] == 'A') ++a;

        rep (j, vs[i].size() - 1)
        {
            if (vs[i].substr(j, 2) == "AB") ++ans;
        }
    }

    if (a == 0 && b == 0) ans += MAX(0, c - 1);
    else if (a == 0 || b == 0) ans += c;
    else ans += MAX(0, MIN(a - 1, b - 1)) + c + 1;

    cout << ans << "\n";
    return 0;
}

