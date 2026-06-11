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
    int l = 1;
    int r = 3;
    for (int i = 2; i <= n - 2; ++i)
    {
        while (l < i && abs(s[i] - s[l] - s[l]) >= abs(s[i] - s[l + 1] - s[l + 1])) ++l;
        while (r < n && abs(s[n] - s[r] - s[r] + s[i]) >= abs(s[n] - s[r + 1] - s[r + 1] + s[i])) ++r;
        s64 P = s[l];
        s64 Q = s[i] - s[l];
        s64 R = s[r] - s[i];
        s64 S = s[n] - s[r];
        s64 large = MAX(P, MAX(Q, MAX(R, S)));
        s64 small = MIN(P, MIN(Q, MIN(R, S)));
        ans = MIN(ans, large - small);
    }

    cout << ans << "\n";
    return 0;
}

