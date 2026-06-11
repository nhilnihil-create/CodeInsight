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

class DisjointSet
{
public:
    DisjointSet() {}
    DisjointSet(int n)
    : p(vs32(n, -1)), w(vs32(n, 0))
    {}
    ~DisjointSet() {}

    bool same(int x, int y)
    {
        x = parent(x);
        y = parent(y);
        return x == y;
    }

    int diff(int x, int y)
    {
        parent(x); parent(y);
        return w[y] - w[x];
    }

    void unite(int x, int y, int d)
    {
        int rx = parent(x);
        int ry = parent(y);

        if (rx == ry) return;

        if (p[rx] > p[ry])
        {
            swap(rx, ry);
            swap(x, y);
            d = -d;
        }
        p[rx] += p[ry];
        p[ry] = rx;
        w[ry] = w[x] + d - w[y];
    }

    int parent(int x)
    {
        int ret;
        if (p[x] < 0)
        {
            ret = x;
        }
        else
        {
            ret = parent(p[x]);
            w[x] += w[p[x]];
            p[x] = ret;
        }
        return ret;
    }

    vs32 p;
    vs32 w;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);
    rep (i, m)
    {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r;
        if (ds.same(l, r) && ds.diff(l, r) != d)
        {
            cout << "No\n";
            return 0;
        }
        else
        {
            ds.unite(l, r, d);
        }
    }

    cout << "Yes\n";
    return 0;
}

