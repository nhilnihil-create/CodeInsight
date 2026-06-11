
#include <iostream>
#include <iomanip> //! for setprecision(10)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int MOD = 1000000007;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int n, m;
    int s[11][11];
    int k[11], p[11];

    cin >> n >> m;
    rep(i, m) {
        cin >> k[i];
        rep(j, k[i]) {
            cin >> s[i][j];
            --s[i][j];
        }
    }
    rep(i, m) cin >> p[i];

    int ans = 0;
    rep(x, 1<<n) {
        bool ok = true;
        rep(i, m) {
            int cnt = 0;
            rep(j, k[i]) {
                if (x & (1 << s[i][j])) {
                    ++cnt;
                }
            }
            if (cnt % 2 != p[i]) {
                ok = false;
                break;
            }
        }
        if (ok) ++ans;
    }
    cout << ans << endl;

    return 0;
}
