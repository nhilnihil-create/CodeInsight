#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

#define ll long long
#define forn(i, n) for (ll i = 0; i < (ll) n; ++i)
#define sz(a) static_cast<int>(a.size())

char buff[(int) 2e6 + 17];
const ll inf = (ll) 1e9 + 7ll;

const int maxn = (int) 2e5 + 17;

int n;
string s;
int ps[maxn];

bool read() {
    if (scanf("%s", buff) != 1)
        return false;

    return true;
}

void solve() {
    s = buff;
    n = sz(s);
    s = "#" + s;
    unordered_map<int, int> dp;
    dp.rehash(2281488);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        ps[i] = ps[i - 1] ^ (1 << (s[i] - 'a'));

        if (!dp.count(ps[i]))
            dp[ps[i]] = inf;

        for (int j = 0; j < 26; ++j) {
            auto t = ps[i] ^ (1 << j);

            if (dp.count(t))
                dp[ps[i]] = min(dp[ps[i]], dp[t] + 1);
        }
    }

    printf("%d\n", max(1, dp[ps[n]]));
}

int main() {
#if SEREZHKA
    freopen("file.in", "r", stdin);
#endif

    while (read())
        solve();

    return 0;
}
