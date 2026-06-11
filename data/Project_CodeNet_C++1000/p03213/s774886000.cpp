#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int n;
    cin >> n;
    map<Int, Int> mp;
    for (Int i = 2; i <= n; i++) {
        Int base = i;
        for (Int j = 2; j * j <= i; j++) {
            while (base % j == 0) {
                base /= j;
                mp[j]++;
            }
        }
        if (base > 1) {
            mp[base]++;
        }
    }
    // 2 4 4
    // 2 24
    // 4 14
    // 74
    Int a = 0;
    Int b = 0;
    Int c = 0;
    Int d = 0;
    Int e = 0;
    for (auto i : mp) {
        if (i.se >= 2) {
            a++;
        }
        if (i.se >= 4) {
            b++;
        }
        if (i.se >= 74) {
            c++;
        }
        if (i.se >= 24) {
            d++;
        }
        if (i.se >= 14) {
            e++;
        }
    }
    dump(b * (b - 1) * (a - 2) / 2 + c + d * (a - 1) + e * (b - 1));
    return 0;
}
