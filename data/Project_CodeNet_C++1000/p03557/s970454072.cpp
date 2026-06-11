
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

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    LL ans = 0;
    for (int y: b) {
        auto ia = lower_bound(a.begin(), a.end(), y);
        LL ac = ia - a.begin();
        auto ic = upper_bound(c.begin(), c.end(), y);
        LL cc = c.end() - ic;
        ans += ac * cc;
    }

    cout << ans << endl;

    return 0;
}
