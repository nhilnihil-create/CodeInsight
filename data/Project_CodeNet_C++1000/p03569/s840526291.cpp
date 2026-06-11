#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;

signed main() {
    string s;
    cin >> s;
    int n = s.size();
    string t;
    rep (i, 0, n) {
        if (s[i] != 'x') t = s[i] + t;
    }
    string t_r = t;
    reverse (t_r.begin(), t_r.end());
    if (t != t_r) {
        cout << "-1\n";
        return 0;
    }
    int ans = 0;
    int i = 0, j = n - 1;
    while (j - i > 0) {
        // cout << i << " " << j << "\n";
        if (s[i] != 'x' && s[j] != 'x') {
            j--, i++;
        } else if (s[i] != 'x') {
            j--;
            ans++;
        } else if (s[j] != 'x') {
            i++;
            ans++;
        } else {
            j--, i++;
        }
    }
    cout << ans << "\n";
}