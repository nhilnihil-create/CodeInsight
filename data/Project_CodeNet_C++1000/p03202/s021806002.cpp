#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

vector<int> x(30);
int m;

inline void add(int i, bool dt = true) {
    if (x[0] == m + 1) return;
    if (x[i] == 0) {
        x[i] = 1;
        rep(j, 0, i) if (x[j] == 0) x[j] = 1;
    } else if (x[i] < m) {
        x[i]++;
        if (dt) rep(j, i + 1, 30) x[j] = 0;
    } else {
        if (i != 0) {
            x[i] = 1;
            if (dt) rep(j, i + 1, 30) x[j] = 0;
            add(i - 1, false);
        } else {
            x[0] = m + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n - 1) {
        if (a[i] >= a[i + 1]) break;
        if (i == n - 2) {
            cout << 1 << endl;
            return 0;
        }
    }
    rep(i, 1, n) {
        if (30 <= a[i - 1] && a[i - 1] < a[i]) {
            a[i - 1] = -1;
        }
        if (30 <= a[i] && a[i] < a[i - 1]) {
            a[i - 1] = -1;
        }
    }
    rep(i, 0, n) a[i] = min(a[i], 30);
    //debug(a);
    int l = 1, r = n;
    while (r - l > 1) {
        m = (r + l) / 2;
        x = vector<int>(30, 0);
        rep(i, 0, n) {
            if (a[i] != -1)
                add(a[i] - 1);
        }
        if (x[0] <= m)
            r = m;
        else
            l = m;
    }
    cout << r << endl;
    return 0;
}