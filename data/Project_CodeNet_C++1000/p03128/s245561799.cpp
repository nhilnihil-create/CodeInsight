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

    const int cost[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

    int n, m;
    cin >> n >> m;
    vs32 a(m);
    rep (i, m)
    {
        cin >> a[i];
        --a[i];
    }

    s64 dp[n + 1];
    rep (i, n + 1) dp[i] = -1;
    dp[0] = 0;

    rep (i, n)
    {
        rep (j, m)
        {
            if (i + cost[a[j]] <= n && dp[i] >= 0)
            {
                dp[i + cost[a[j]]] = MAX(dp[i + cost[a[j]]], dp[i] + 1);
            }
        }
    }

    string ans = "";
    int idx = n;
    while (idx != 0)
    {
        int temp = 0;
        rep (i, m)
        {
            if (dp[idx] == 1)
            {
                if (idx - cost[a[i]] == 0)
                {
                    temp = MAX(temp, a[i] + 1);
                }
            }
            else if (idx - cost[a[i]] > 0 && dp[idx] == dp[idx - cost[a[i]]] + 1)
            {
                temp = MAX(temp, a[i] + 1);                
            }
        }
        ans += to_string(temp);
        idx -= cost[temp - 1];
    }

    cout << ans << "\n";
    return 0;
}

