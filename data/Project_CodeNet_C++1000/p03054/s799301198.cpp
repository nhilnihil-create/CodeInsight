#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(10);
    int h, w, n;
    cin >> h >> w >> n;
    int sc, sr;
    cin >> sr >> sc;
    string s, t;
    cin >> s >> t;
    int l = 0, r = w + 1, u = 0, d = h + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (t[i] == 'U') {
            if (d != h + 1)
                d++;
        } else if (t[i] == 'D') {
            if (u != 0)
                u--;
        } else if (t[i] == 'L') {
            if (r != w + 1)
                r++;
        } else {
            if (l != 0)
                l--;
        }
        if (s[i] == 'U') {
            u++;
        } else if (s[i] == 'D') {
            d--;
        } else if (s[i] == 'L') {
            l++;
        } else {
            r--;
        }
        if (r - l <= 1 || d - u <= 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (l < sc && sc < r && u < sr && sr < d)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}