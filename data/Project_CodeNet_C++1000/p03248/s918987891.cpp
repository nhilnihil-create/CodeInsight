#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> a;
    int n = s.size();
    if (s[n - 1] == '1' || s[0] == '0') {
        cout << -1 << endl;
        return 0;
    }
    rep(i, 0, n) {
        if (i > n - 2 - i) break;
        if (s[i] != s[n - 2 - i]) {
            cout << -1 << endl;
            return 0;
        }
        if (s[i] == '1') {
            a.emplace_back(i + 1);
        }
    }
    int cnt = 1;
    rep(i, 0, a.size() - 1) {
        cout << cnt << ' ' << cnt + 1 << endl;
        cnt++;
    }
    cout << cnt << ' ' << n << endl;
    cnt++;
    rep(i, 1, a.size()) {
        rep(j, 0, a[i] - a[i - 1] - 1) {
            cout << i + 1 << ' ' << cnt << endl;
            cnt++;
        }
    }
    rep(i, cnt, n) {
        cout << i << ' ' << n << endl;
    }

    return 0;
}