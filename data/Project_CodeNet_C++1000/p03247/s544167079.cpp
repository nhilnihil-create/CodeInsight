#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int X[maxn], Y[maxn];
char s[32];

int iabs (int x) {
    return x >= 0 ? x : -x;
}

int main () {
    int n, c = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> X[i] >> Y[i];
        if ((X[i] + Y[i]) & 1) ++c;
        else --c;
    }
    if (iabs(c) != n) {
        cout << -1 << endl;
        return 0;
    }
    int m = 31 + (c < 0);
    cout << m << endl;
    for (int i = 0; i <= 30; ++i) {
        cout << (1 << i) << ' ';
    }
    if (c < 0) cout << 1 << ' ';
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        int x = X[i], y = Y[i], sgn = 0;
        if (c < 0) s[31] = 'R', --x;
        for (int j = 30; j >= 0; --j) {
            if (iabs(x) < iabs(y)) swap(x, y), sgn ^= 1;
            if (x > 0) x -= 1 << j, s[j] = sgn ? 'U' : 'R';
            else x += 1 << j, s[j] = sgn ? 'D' : 'L';
        }
        cout << (string)s << endl;
    }
    return 0;
}
