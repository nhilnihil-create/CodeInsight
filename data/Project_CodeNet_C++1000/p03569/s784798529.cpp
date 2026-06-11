#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int l = 0, r = s.size() - 1;

    bool b = true;
    int cnt = 0;

    while (l <= r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            if (s[l] == 'x' && s[r] != 'x') {
                l++;
                cnt++;
            } else if (s[l] != 'x' && s[r] == 'x') {
                r--;
                cnt++;
            } else {
                b = false;
                break;
            }
        }
    }

    if (b) {
        cout << cnt << endl;

    } else {
        cout << -1 << endl;
    }

    // vi a(26, 0);
    // rep(i, s.size()) {
    //     a[s[i] - 'a']++;
    // }

    // string ss = s;

    // reverse(ss.begin(), ss.end());

    // if (s == ss) {
    //     cout << 0 << endl;
    // } else {
    //     string s2;

    //     rep(i, s.size()) {
    //         if (s[i] != 'x') {
    //             s2 += s[i];
    //         }
    //     }

    //     string ss2 = s2;
    //     reverse(ss2.begin(), ss2.end());

    //     if (s2 == ss2) {
    //         int ans = 0;

    //         vi c(ss2.size() + 1, 0);
    //         int idx = 0;

    //         rep(i, s.size()) {
    //             if (s[i] == 'x') {
    //                 c[idx]++;
    //             } else if (s[i] == s2[idx]) {
    //                 idx++;
    //             }
    //         }

    //         for (int i = 0; i < c.size() / 2; i++) {
    //             int t1, t2;
    //             t1 = c[i];
    //             t2 = c[c.size() - 1 - i];

    //             ans += max(t1, t2) - min(t1, t2);
    //         }

    //         cout << ans << endl;

    //     } else {
    //         cout << -1 << endl;
    //     }
    // }
}