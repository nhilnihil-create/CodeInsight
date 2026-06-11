
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

int count(int x) {
    int ret = 2;
    for (int d = 2; d*d <= x; ++d) {
        if (x % d == 0) {
            ++ret;
            if (d*d < x) ++ret;
        }
    }
    return ret;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int ans = 0;
    for (int x = 1; x <= n; x += 2) {
        if (count(x) == 8) ++ans;
    }
    cout << ans << endl;

    return 0;
}
