#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int wcnt = 0;
    rep(i, 0, s.size()) {
        if (s[i] == '.') {
            wcnt++;
        }
    }

    int bcnt = 0;

    // all black
    int ans = wcnt;
    // b and w
    rep(i, 0, s.size()) {
        if (s[i] == '.') {
            wcnt--;
        } else {
            bcnt++;
        }

        ans = min(bcnt + wcnt, ans);
    }

    // all white;
    ans = min(bcnt, ans);

    cout << ans << endl;

    return 0;
}
