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

    vs64 ans;
    ans.push_back(2);
    ans.push_back(3);
    ans.push_back(25);

    int num = 3;
    s64 a = 4;
    for (; num + 15 <= n && a + 32 <= 30000;)
    {
        rep (i, 15)
        {
            if (a % 30 != 0 && a <= 30000)
            {
                ans.push_back(a);
                ++num;
            }
            a += 2;
        }
    }

    a = 9;
    for (; num + 10 <= n && a + 9 * 9 <= 30000; num += 10)
    {
        rep (i, 10)
        {
            ans.push_back(a);
            a += 6;
        }
    }

    a = 35;
    for (; num + 2 <= n && a + 20 <= 30000; num += 2)
    {
        rep (i, 2)
        {
            ans.push_back(a);
            a += 20;
        }
        a += 20;
    }
    
    a = 30;
    for (; num < n; ++num)
    {
        ans.push_back(a);
        a += 30;
    }

    rep (i, ans.size())
    {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}

