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

    int h, w, D;
    cin >> h >> w >> D;
    vector< pair<int ,int> > m(h * w + 1);
    int a;
    rep (i, h)
    {
        rep (j, w)
        {
            cin >> a;
            m[a] = make_pair(i, j);
        }
    }

    vector< vs32 > d(h, vs32(w));
    rep (i, D)
    {
        int sx = m[h * w - i].second;
        int sy = m[h * w - i].first;
        d[sy][sx] = 0;
        for (int j = h * w - i - D; j > 0; j -= D)
        {
            int tx = m[j].second;
            int ty = m[j].first;
            d[ty][tx] = d[sy][sx] + abs(sx - tx) + abs(sy - ty);
            sx = tx;
            sy = ty;
        }
    }

    int q;
    cin >> q;
    int l, r;
    rep (i, q)
    {
        cin >> l >> r;
        int sx = m[l].second;
        int sy = m[l].first;
        int tx = m[r].second;
        int ty = m[r].first;
        cout << d[sy][sx] - d[ty][tx] << "\n";
    }

    return 0;
}

