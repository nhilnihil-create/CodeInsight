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

    string s;
    cin >> s;

    vector< bool > used(27, false);
    rep (i, s.size())
    {
        used[s[i] - 'a'] = true;
    }

    int idx = 0;
    for (; idx < 26; ++idx)
    {
        if (!used[idx]) break;
    }

    string ans;
    int pos = -1;
    for (int i = s.size() - 1; i > 0; --i)
    {
        if (s[i - 1] < s[i])
        {
            pos = i - 1;
            break;
        }
    }

    if (idx == 26)
    {
        if (pos == -1) ans = "-1";
        else
        {
            char c = 'z';
            for (idx = pos; idx < s.size(); ++idx)
            {
                if (s[idx] > s[pos] && c > s[idx])
                {
                    c = s[idx];
                }
            }
            ans = s.substr(0, pos) + c;
        }
    }
    else
    {
        ans = s + (char)(idx + 'a');
    }

    cout << ans << "\n";
    return 0;
}

