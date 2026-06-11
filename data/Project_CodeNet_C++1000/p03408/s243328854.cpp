#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
    //入力
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
    }
    int m;
    cin >> m;
    vector<string> t(m);
    rep(i, m) {
        cin >> t[i];
    }
    int mx = max(n, m);
    vector<string>st(mx);
    vector<int>cnt(mx);
    rep(i, n) {
        rep(j, mx) {
            if (st[j] == s[i]) {
                ++cnt[j];
            }
            else if (st[j]=="") {
                st[j] = s[i];
                ++cnt[j];
                break;
            }
        }
    }
    rep(i, m) {
        rep(j, mx) {
            if (st[j] == t[i]) {
                --cnt[j];
            }
            else if (st[j] == "") {
                st[j] = t[i];
                --cnt[j];
                break;
            }
        }
    }
    int ans = 0;
    rep(i, mx) {
        ans = max(ans, cnt[i]);
    }
    if (ans < 0) ans = 0;

    cout << ans << endl;
    return 0;
}
