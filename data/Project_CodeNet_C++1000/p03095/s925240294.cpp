#pragma GCC optimize("O3")
#pragma GCC target("avx")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
using llong = long long;

const llong mod = (llong)(1e9) + 7;
llong n;
char s[100005];
llong cnt[26];

int main() {
    scanf("%lld %s", &n, s);

    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    /*
    llong ans = 0;
    for (llong i = 1; i < (1 << 26); i++) {
        //bitset<26> b(i);
        llong b = i;
        llong tmp = 1;

        for (int j = 0; j < 26; j++) {
            if (b & 1) {
                tmp *= cnt[j];
                if (cnt[j] == 0) break;
                tmp %= mod;
            }
            b >>= 1;
        }

        ans += tmp;
        if (ans >= mod) ans -= mod;
    }
    */

    llong ans = 1;
    for (llong i = 0; i < 26; i++) {
        if (cnt[i]) ans *= (cnt[i] + 1);
        ans %= mod;
    }
    ans = (ans + mod - 1) % mod;

    cout << ans << endl;

    return 0;
}
