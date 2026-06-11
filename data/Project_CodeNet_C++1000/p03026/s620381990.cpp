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

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
vs32 color;
vs32 degree;
int idx;

s64 dfs(int x, vector<vs32>& t, vs32& c, vs32& num)
{
    s64 ret = 0;

    color[x] = GRAY;
    for (auto a : t[x])
    {
        if (color[a] != WHITE) continue;
        color[a] = GRAY;
        ret += dfs(a, t, c, num);
    }
    if (color[x] != BLACK)
    {
        color[x] = BLACK;
        num[x] = c[idx];
        ret += c[idx];
        ++idx;
    }

    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vs32> t(n);
    degree.resize(n, 0);
    color.resize(n, WHITE);
    int a, b;
    rep (i, n - 1)
    {
        cin >> a >> b;
        --a; --b;
        t[a].push_back(b);
        t[b].push_back(a);
        ++degree[a];
        ++degree[b];
    }

    vs32 c(n);
    rep (i, n) cin >> c[i];
    sort(c.begin(), c.end());

    vs32 ans(n);
    s64 score = dfs(0, t, c, ans);

    cout << score - c[n - 1] << "\n";
    rep (i, n)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}

