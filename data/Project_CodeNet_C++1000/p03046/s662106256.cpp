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

    int m, k;
    cin >> m >> k;
    if (k >= (1 << m))
    {
        cout << "-1\n";
        return 0;
    }

    vs32 cand;
    if (k == 1)
    {
        if (m == 1)
        {
            cout << "-1\n";
            return 0;
        }
        cand.push_back(2);
        cand.push_back(3);
    }
    else
    {
        int temp = k;
        int cnt = 0;
        while (temp)
        {
            if (temp & 1)
            {
                if (k == (1 << cnt))
                {
                    cand.push_back((1 << cnt) + (1 << (cnt - 1)));
                    cand.push_back(1 << (cnt - 1));
                    break;
                }
                else
                {
                    cand.push_back(1 << cnt);
                }
            }
            ++cnt;
            temp >>= 1;
        }
    }

    vs32 ans(1 << (m + 1));
    vs32 cand2;
    rep (i, 1 << m)
    {
        bool flag = true;
        rep (j, cand.size()) if (i == cand[j] || i == k) flag = false;
        if (flag) cand2.push_back(i);
    }

    int idx = 0;
    for (auto it = cand2.rbegin(); it < cand2.rend(); ++it)
    {
        ans[idx++] = *it;
    }
    for (auto it = cand.rbegin(); it < cand.rend(); ++it)
    {
        ans[idx++] = *it;
    }
    for (auto it = cand2.begin(); it < cand2.end(); ++it)
    {
        ans[idx++] = *it;
    }
    ans[idx++] = k;
    for (auto it = cand.begin(); it < cand.end(); ++it)
    {
        ans[idx++] = *it;
    }
    ans[idx++] = k;

    rep (i, ans.size())
    {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}

