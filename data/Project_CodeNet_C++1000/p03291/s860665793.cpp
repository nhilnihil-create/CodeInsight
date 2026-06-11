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

s64 mypow(s64 x, s64 n)
{
    s64 ret = 1;
    while (n > 0)
    {
        if (n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    const int a = 0;
    const int b = 1;
    const int c = 2;
    const int q = 3;

    vector< vs32 > pos(4);

    rep (i, s.size())
    {
        if (s[i] == '?')
        {
            pos[q].push_back(i);
        }
        else
        {
            pos[s[i] - 'A'].push_back(i);
        }
    }

    s64 ans = 0;
    rep (i, pos[b].size())
    {
        auto ita = lower_bound(pos[a].begin(), pos[a].end(), pos[b][i]);
        auto itc = lower_bound(pos[c].begin(), pos[c].end(), pos[b][i]);
        auto itq = lower_bound(pos[q].begin(), pos[q].end(), pos[b][i]);

        s64 numa = (ita == pos[a].begin() ? 0 : ita - pos[a].begin());
        s64 numc = pos[c].end() - itc;
        s64 numq = (itq == pos[q].begin() ? 0 : itq - pos[q].begin());

        ans += (((numa * mypow(3, numq) % MOD + numq * mypow(3, numq - 1) % MOD) % MOD) *
            ((numc * mypow(3, pos[q].size() - numq) % MOD + (pos[q].size() - numq) * mypow(3, pos[q].size() - numq - 1) % MOD) % MOD)) % MOD;
        ans %= MOD;
    }
    rep (i, pos[q].size())
    {
        auto ita = lower_bound(pos[a].begin(), pos[a].end(), pos[q][i]);
        auto itc = lower_bound(pos[c].begin(), pos[c].end(), pos[q][i]);

        s64 numa = (ita == pos[a].begin() ? 0 : ita - pos[a].begin());
        s64 numc = pos[c].end() - itc;

        ans += (((numa * mypow(3, i) % MOD + i * (mypow(3, i - 1)) % MOD) % MOD) *
                ((numc * mypow(3, pos[q].size() - i - 1) % MOD + (pos[q].size() - i - 1) * mypow(3, pos[q].size() - i - 2) % MOD) % MOD)) % MOD;
        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}

