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

class Rect
{
public:
    Rect() {}
    Rect(int x1, int y1, int x2, int y2)
    : ld(make_pair(MIN(x1, x2), MIN(y1, y2))),
    ru(make_pair(MAX(x1, x2), MAX(y1, y2)))
    {}
    ~Rect() {}

    bool in(pair<int, int>& x)
    {
        return ld.first <= x.first  && ld.second <= x.second && ru.first >= x.first && ru.second >= x.second;
    }

    s64 size()
    {
        return (s64)(ru.first - ld.first) * (s64)(ru.second - ld.second);
    }

private:
    pair<int, int> ld;
    pair<int, int> ru;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector< pair<int, int> > p(N);
    rep (i, N)
    {
        cin >> p[i].first >> p[i].second;
    }

    s64 ans = 4 * 1e18;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            for (int m = 0; m < N; ++m)
            {
                for (int n = m + 1; n < N; ++n)
                {
                    Rect rect(p[i].first, p[m].second, p[j].first, p[n].second);
                    int num = 0;
                    rep (k, N)
                    {
                        if (rect.in(p[k]))
                        {
                            ++num;
                        }
                    }
                    if (num >= K)
                    {
                        ans = MIN(rect.size(), ans);
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

