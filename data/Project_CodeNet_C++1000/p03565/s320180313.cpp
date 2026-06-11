
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
    const string NG = "UNRESTORABLE";

	cin.tie(0);
	ios::sync_with_stdio(0);

    string s, t;
    cin >> s >> t;

    string ans = NG;
    for (int offset = 0; offset+t.length() <= s.length(); ++offset) {
        // cout << "offset = " << offset << endl;
        bool ok = true;
        rep(i, t.length()) {
            if (s[i+offset] != '?' && s[i+offset] != t[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            // cout << "  OK" << endl;
            string cand;
            rep(i, offset) {
                cand += (s[i] == '?' ? 'a' : s[i]);
            }
            cand += t;
            for (int i = offset+t.length(); i < s.length(); ++i) {
                cand += (s[i] == '?' ? 'a' : s[i]);
            }
            if (ans == NG || cand < ans) {
                ans = cand;
            }
        // } else {
        //     cout << "  NG" << endl;
        }
    }


    cout << ans << endl;
    

    return 0;
}
