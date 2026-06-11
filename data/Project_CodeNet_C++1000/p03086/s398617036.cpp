
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

    string s;
    cin >> s;

    int ans = 0;
    int curr = 0;
    rep(i, s.length()) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            ++curr;
        } else {
            ans = max(ans, curr);
            curr = 0;
        }
    }
    ans = max(ans, curr);

    cout << ans << endl;

    return 0;
}
